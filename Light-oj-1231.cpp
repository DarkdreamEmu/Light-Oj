#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int co,taka;
        scanf("%d %d",&co,&taka);
        int coin[co+10];
        int value[co+10];
        int dp[110][1110];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=co; i++){
            scanf("%d",&coin[i]);
        }
        for(int i=1; i<=co; i++){
            scanf("%d",&value[i]);
        }
        dp[0][0]=1;
        for(int i=1; i<=co; i++){
            for(int j=0; j<=taka; j++){
                for(int k=0; j+k*coin[i]<=taka&&k<=value[i]; k++){
                    dp[i][j+k*coin[i]]=(dp[i][j+k*coin[i]]+dp[i-1][j])%MOD;
                }
            }
        }
        /*for(int i=1; i<=co; i++){
            for(int j=0; j<=taka; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        printf("Case %d: %d\n",cs++,dp[co][taka]);
    }
    return 0;
}
