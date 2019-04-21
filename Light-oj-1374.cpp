#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
       int n;
       scanf("%d",&n);
       int A[n+10];
       int mx=-1;
       int F[n+10];
       int M[n+10];
       memset(F,0,sizeof(F));
       memset(M,0,sizeof(M));
       bool ok=true;
       for(int i=0; i<n; i++){
            scanf("%d",&A[i]);
            mx=max(mx,A[i]);
            F[A[i]]++;
            if(A[i]>=n||F[A[i]]>2){
                ok=false;
            }
       }
       printf("Case %d: ",cs++);
       if(!ok)puts("no");
       else{
            for(int i=0; i<n; i++){
                if(F[A[i]]){
                    if(!M[A[i]]){
                        M[A[i]]++;
                    }
                    else if(M[A[i]]==1&&M[n-1-A[i]]==0){
                        M[n-1-A[i]]++;
                    }
                    else{
                        ok=false;
                        break;
                    }
                }
            }
            if(ok)puts("yes");
            else puts("no");
       }
    }
    return 0;
}
