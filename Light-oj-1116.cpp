#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        long long even=1,odd=1,cnt=0;
        printf("Case %d: ",cs++);
        if(n%2)puts("Impossible");
        else{
            while(n%2==0){
                n/=2;
                even*=2;
            }
            odd=n;
            printf("%lld %lld\n",odd,even);
        }
    }
    return 0;
}
