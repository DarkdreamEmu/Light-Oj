#include "bits/stdc++.h"
using namespace std;

int N,K;
int Arr[1010];

bool possible(int mid){
    int sum=0,cnt=0;
    for(int i=0; i<N; i++){
        sum+=Arr[i];
        if(sum>mid){
            cnt++;
            sum=Arr[i];
        }
    }
    cnt++;
    return cnt<=K;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int L=-1,H=0;
        scanf("%d %d",&N,&K);
        for(int i=0; i<N; i++)scanf("%d",&Arr[i]),L=max(L,Arr[i]),H+=Arr[i];
        int Res=L;
        while(L<=H){
            int mid=(L+H)/2;
            if(possible(mid)){
                Res=mid;
                H=mid-1;
            }
            else L=mid+1;
        }
        printf("Case %d: %d\n",cs++,Res);
    }
    return 0;
}
