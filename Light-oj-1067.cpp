#include "bits/stdc++.h"
using namespace std;

#define LL long long
LL MOD=1000003;

LL Bigmod(LL x,LL n,LL MOD){
    if(n==0)return 1;
    if(n%2==0)return ((Bigmod(x,n/2,MOD)%MOD)*(Bigmod(x,n/2,MOD)%MOD)%MOD);
    else return ((Bigmod(x,n/2,MOD)%MOD)*(Bigmod(x,n/2,MOD)%MOD*x))%MOD;
}

LL ModInverse(LL x,LL MOD){
    return Bigmod(x,MOD-2,MOD);
}

int Fact[1000010];

int main(){
    Fact[0]=Fact[1]=1;
    for(int i=2; i<=1000010; i++){
        Fact[i]=((Fact[i-1]%MOD)*(i%MOD))%MOD;
    }
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        LL Up=Fact[n]%MOD;
        LL down=((Fact[k]%MOD)*(Fact[n-k]%MOD)%MOD);
        down=ModInverse(down,MOD);
        LL ans=(Up*(down%MOD))%MOD;
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
