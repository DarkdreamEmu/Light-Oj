#include "bits/stdc++.h"
using namespace std;

map<int, vector< pair<int,int> > >my;
int cnt=0;
int freq[110];

void prime_divisor(int n){
    while(n%2==0){
        cnt++;
        n/=2;
    }
    if(cnt){
        freq[2]+=cnt;
    }
    int sq=sqrt(n);
    for(int i=3; i<=sq; i+=2){
        cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        if(cnt){
            freq[i]+=cnt;
        }
    }
    if(n>2){
        freq[n]+=1;
    }
    cnt=0;
}

void ans_me(){
    vector< pair<int,int> >rec;
    for(int i=1; i<=100; i++){
        memset(freq,0,sizeof(freq));
        for(int j=1; j<=i; j++){
            prime_divisor(j);
        }
        for(int k=1; k<=i; k++){
            if(freq[k]){
                rec.push_back(make_pair(k,freq[k]));
            }
        }
        my[i]=rec;
        sort(my[i].begin(),my[i].end());
        rec.clear();
        cnt=0;
    }
}

int main(){
    ans_me();
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sz=my[n].size();
        printf("Case %d: %d = ",cs++,n);
        for(int i=0; i<sz; i++){
            cout<<my[n][i].first<<" ("<<my[n][i].second<<")";
            if(i<sz-1){
                cout<<" * ";
            }
        }
        puts("");
    }
    return 0;
}
