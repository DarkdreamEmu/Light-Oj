#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int>vec;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n; j++){
                int sum=vec[i]+vec[j];
                int ind=lower_bound(vec.begin(),vec.end(),sum)-vec.begin();
                ans+=max(0,ind-j-1);
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
