#include "bits/stdc++.h"
using namespace std;

long long divi[1000010];
long long sequence[1000010];

int main(){
    for(long long i=1; i<=1000000; i++){
        for(long long j=i; j<=1000000; j+=i){
            divi[j]++;
        }
    }
    sequence[0]=1;
    for(long long i=1; i<=1000000; i++){
        sequence[i]=sequence[i-1]+divi[sequence[i-1]];
    }
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%lld %lld",&a,&b);
        printf("Case %d: ",cs++);
        cout<<distance(lower_bound(sequence,sequence+1000000,a),upper_bound(sequence,sequence+1000000,b))<<endl;
    }
    return 0;
}

