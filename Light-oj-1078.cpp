#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        long long num=0,cnt=0;
        for(int i=0; i<n; i++){
            num=(num*10+k)%n;
            cnt++;
            if(num==0)break;
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
