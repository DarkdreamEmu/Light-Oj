#include "bits/stdc++.h"
using namespace std;

#define LL long long
LL N;

LL valid(LL mid){
    LL cnt=0;
    for(LL i=5; mid/i>=1; i*=5){
        cnt+=(mid/i);
    }
    return cnt;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&N);
        LL L=1,H=10e10,Res=1000000000000000000;
        for(int i=0; i<50; i++){
            LL mid=(L+H)/2;
            if(valid(mid)<N)L=mid+1;
            else if(valid(mid)>N)H=mid-1;
            else Res=mid,H=mid-1;
        }
        if(Res!=1000000000000000000)printf("Case %d: %lld\n",cs++,Res);
        else printf("Case %d: impossible\n",cs++);
    }
    return 0;
}
