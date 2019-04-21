#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int>my,notmy;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            my.push_back(a);
        }
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            notmy.push_back(a);
        }
        sort(my.begin(),my.end());
        sort(notmy.begin(),notmy.end());
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(my[i]>notmy[j]&&notmy[j]!=-1){
                    res+=2;
                    my[i]=notmy[j]=-1;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(my[i]!=-1){
                for(int j=0; j<n; j++){
                    if(notmy[j]!=-1&&my[i]==notmy[j]){
                        res+=1;
                        my[i]=notmy[j]=-1;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
