#include "bits/stdc++.h"
using namespace std;

int dp[110][110];

int ans_me(char s[],int L,int R){
    if(L==R)return 0;
    if(L==R-1)return (s[L]==s[R] ? 0: 1);
    if(L>R)return 0;
    if(dp[L][R]!=-1)return dp[L][R];
    if(s[L]==s[R])return dp[L][R]=ans_me(s,L+1,R-1);
    return dp[L][R]=min(ans_me(s,L+1,R),ans_me(s,L,R-1))+1;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        char s[110];
        scanf("%s",&s);
        memset(dp,-1,sizeof(dp));
        int res=ans_me(s,0,strlen(s)-1);
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
