#include "bits/stdc++.h"
using namespace std;

int cost[110][110];

int main(){
    int t,n,m,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)cost[i][j]=0;
                else cost[i][j]=10000000;
            }
        }
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            cost[u][v]=1;
            cost[v][u]=1;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int u,v;
        scanf("%d %d",&u,&v);
        int res=0;
        for(int i=0; i<n; i++){
            if(cost[u][i]!=10000000&&cost[i][v]!=10000000){
                res=max(res,cost[u][i]+cost[i][v]);
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
