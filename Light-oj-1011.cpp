#include "bits/stdc++.h"
using namespace std;

int M[20][20];
long long dp[20][1<<20];
int N;

int SET(int mask,int pos){return (mask|(1<<pos));}
int check(int mask,int pos){return (mask&(1<<pos));}

int ans_me(int boy,int mask){
    if(mask==(1<<N)-1)return 0;
    if(boy>=N)return 0;
    if(dp[boy][mask]!=-1)return dp[boy][mask];
    int ans=0;
    for(int i=0; i<N; i++){
        if(check(mask,i))continue;
        int newmask=SET(mask,i);
        ans=max(ans,ans_me(boy+1,newmask)+M[boy][i]);
    }
    return dp[boy][mask]=ans;
}


int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d",&M[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        long long ans=ans_me(0,0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
