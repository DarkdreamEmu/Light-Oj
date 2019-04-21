#include "bits/stdc++.h"
using namespace std;

long long dp[52][52][52];
int vis[52][52][52];

long long ans_me(int n,int k,int m){
    if(vis[n][k][m])return dp[n][k][m];
    vis[n][k][m]=1;
    if(k==0&&n==0)return dp[n][k][m]=1LL;
    if(k==0)return dp[n][k][m]=0LL;
    long long ans=0;
    for(int i=1; i<=m; i++){
        if(n-i>=0)ans=ans+ans_me(n-i,k-1,m);
        else break;
    }
    return dp[n][k][m]=ans;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,k,m;
        scanf("%d %d %d",&n,&k,&m);
        long long res=ans_me(n,k,m);
        printf("Case %d: %lld\n",cs++,res);
    }
    return 0;
}
