#include "bits/stdc++.h"
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,e,f,n;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        long long fib[10010];
        fib[0]=a;
        fib[1]=b;
        fib[2]=c;
        fib[3]=d;
        fib[4]=e;
        fib[5]=f;
        for(int i=6; i<=n; i++){
            fib[i]=(fib[i-1] + fib[i-2] + fib[i-3] + fib[i-4] + fib[i-5] + fib[i-6])%10000007;
        }
        printf("Case %d: %d\n",cs++,fib[n]%10000007);
    }
    return 0;
}
