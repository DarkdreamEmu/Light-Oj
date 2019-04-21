#include "bits/stdc++.h"
using namespace std;

#define LL long long

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        LL X[n+10],Y[n+10];
        for(int i=0; i<n; i++){
            LL num;
            scanf("%lld",&num);
            X[i]=num;
            Y[n-i-1]=num;
        }
        int dp[n+10],store[n+10];
        int length=0;
        for(int i=0; i<n; i++){
            int low=1,high=length;
            while(low<=high){
                int mid=ceil((low+high)/2);
                if(Y[dp[mid]]>Y[i]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            int pos=low;
            store[n-i-1]=pos;
            dp[pos]=i;
            if(pos>length){
                length=pos;
            }
        }
        printf("Case %d:\n",cs++);
        while(q--){
            int range;
            scanf("%d",&range);
            if(range>length)printf("Impossible\n");
            else{
                int cnt=0;
                LL prev=-2222222222;
                LL space=range;
                for(int i=0; i<n&&cnt<space; i++){
                    if(store[i]>=range&&X[i]>prev){
                        prev=X[i];
                        printf("%lld",X[i]);
                        if(cnt<space-1)printf(" ");
                        cnt++;
                        range--;
                    }
                    else{
                        continue;
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}

/**3 4 1 2 3 6
   3 2 4 3 2 1
**/
