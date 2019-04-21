#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int res=0;
        for(int i=0; i<n; i++){
            int take=0;
            for(int j=0; j<m; j++){
                int num;
                scanf("%d",&num);
                take+=num;
            }
            res^=take;
        }
        printf("Case %d: ",cs++);
        if(res)puts("Alice");
        else puts("Bob");
    }
    return 0;
}
