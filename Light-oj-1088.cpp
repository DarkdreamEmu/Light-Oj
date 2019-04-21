#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        vector<int>vec;
        vec.clear();
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            vec.push_back(a);
        }
        printf("Case %d:\n",cs++);
        for(int i=0; i<k; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            int low=lower_bound(vec.begin(),vec.end(),u)-vec.begin();
            int high=upper_bound(vec.begin(),vec.end(),v)-vec.begin();
            printf("%d\n",high-low);
        }
    }
    return 0;
}
