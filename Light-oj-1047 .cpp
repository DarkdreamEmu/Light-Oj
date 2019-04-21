#include "bits/stdc++.h"
using namespace std;

int Cost[22][4];
int dp[22][22];
int n;

int ans_me(int pos,int color){
    if(pos<0)return 0;
    int ans=INT_MAX;
    if(dp[pos][color]!=-1)return dp[pos][color];
    for(int i=0; i<3; i++){
        if(color!=i){
            ans=min(ans,ans_me(pos-1,i));
        }
    }
    return dp[pos][color]=ans+Cost[pos][color];
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d %d %d",&Cost[i][0],&Cost[i][1],&Cost[i][2]);
        }
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        int res=min(ans,ans_me(n-1,0));
        res=min(res,ans_me(n-1,1));
        res=min(res,ans_me(n-1,2));
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
