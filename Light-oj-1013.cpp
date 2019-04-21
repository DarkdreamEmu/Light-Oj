#include "bits/stdc++.h"
using namespace std;

int dp[40][40];
long long tp[110][40][40];

string a,b;
int lenght;

int LCS(int i,int j){
    if(i>=a.size() || j>=b.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    if(a[i]==b[j])ans=1+LCS(i+1,j+1);
    else{
        ans=max(LCS(i+1,j),LCS(i,j+1));
    }
    return dp[i][j]=ans;
}

long long ans_me(int cur,int i,int j){
    if(cur==lenght){
        if(i==a.size() && j==b.size())return 1;
        else return 0;
    }
    if(tp[cur][i][j]!=-1)return tp[cur][i][j];
    long long ans=0;
    if(a[i]==b[j])ans=ans_me(cur+1,i+1,j+1);
    else{
        ans=ans_me(cur+1,i+1,j)+ans_me(cur+1,i,j+1);
    }
    return tp[cur][i][j]=ans;
}

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>a>>b;
        memset(dp,-1,sizeof(dp));
        lenght=(int)a.size()+(int)b.size()-LCS(0,0);
        memset(tp,-1,sizeof(tp));
        long long number=ans_me(0,0,0);
        printf("Case %d: %d %lld\n",cs++,lenght,number);
    }
    return 0;
}
