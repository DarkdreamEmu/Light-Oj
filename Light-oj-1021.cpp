#include "bits/stdc++.h"
using namespace std;

long long dp[30][1<<17];
string s;
int ar[100];
int base,k;

int SET(int mask,int pos){return (mask|(1<<pos));}
int check(int mask,int pos){return (mask&(1<<pos));}

long long ans_me(long long cur,int mask){
    if(mask==(1<< (int)(s.size()))-1)return cur==0;
    if(dp[cur][mask]!=-1)return dp[cur][mask];
    long long ans=0;
    for(int i=0; i<s.size(); i++){
        if(check(mask,i))continue;
        int newmask=SET(mask,i);
        ans+=ans_me( (cur*base+ar[i])%k,newmask);
    }
    return dp[cur][mask]=ans;
}

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>base>>k>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9')ar[i]=s[i]-'0';
            else ar[i]=s[i]-'A'+10;
        }
        memset(dp,-1,sizeof(dp));
        long long ans=ans_me(0,0);
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
