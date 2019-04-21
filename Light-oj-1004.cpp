#include "bits/stdc++.h"
using namespace std;

int mat[505][505];
int dp[505][505];

int n;

int ans_me(int r,int c){
    if(r>=2*n || c>n)return 0;
    if(dp[r][c]!=-1)return dp[r][c];
    int ans=0;
    if(r<=n-1){
        ans=max(ans,ans_me(r+1,c+1)+mat[r][c]);
        ans=max(ans,ans_me(r+1,c)+mat[r][c]);
    }
    else{
        ans=max(ans,ans_me(r+1,c)+mat[r][c]);
        ans=max(ans,ans_me(r+1,c-1)+mat[r][c]);
    }
    return dp[r][c]=ans;
}

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        memset(mat,0,sizeof(mat));
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cin>>mat[i][j];
            }
        }
        for(int i=1; i<=n-1; i++){
            for(int j=1; j<=n-i; j++){
                cin>>mat[n+i][j];
            }
        }
        int ans=ans_me(1,1);
        printf("Case %d: %d\n",cs,ans);
        cs++;
    }
    return 0;
}
