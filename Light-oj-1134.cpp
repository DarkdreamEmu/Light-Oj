#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int dp[m+10];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        long long sum=0,cnt=0;
        for(int i=0; i<n; i++){
            int num;
            scanf("%d",&num);
            sum=(sum+num)%m;
            cnt+=dp[sum];
            dp[sum]++;
        }
        printf("Case %d: %lld\n",cs++,cnt);
    }
    return 0;
}
