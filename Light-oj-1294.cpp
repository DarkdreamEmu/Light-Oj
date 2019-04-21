#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        printf("Case %d: %lld\n",cs++,(m*n)/2);
    }
    return 0;
}
