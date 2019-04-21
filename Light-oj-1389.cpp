/**Bismillah-ir-Rahman-ir-Rahim**/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(LL i=0; i<n; i++)
#define RFOR(i,n) for(LL i=n-1; i>=0; i--)
#define FILL(A,value) memset(A,value,sizeof(A))
#define LL long long int
#define sI(a) scanf("%d",&a)
#define pI(a) printf("%d",a)
#define sI2(a,b) sI(a),sI(b)
#define pI2(a,b) pI(a) , pI(b)
#define sL(a) scanf("%lld",&a)
#define pL(a) printf("%lld",a)
#define sL2(a,b) sL(a),sL(b)
#define pL2(a,b) pL(a) , pL(b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pN printf("\n")
#define pS printf(" ");
#define N 1000001
#define PI 3.14159

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        int sz=s.size();
        int visited[110];
        memset(visited,0,sizeof(visited));
        bool ok=true;
        int res=0;
        if(n==1&&s=="#"){res=0; ok=false;}
        if(n==1&&s=="."){res=1; ok=false;}
        for( int i=0; i<sz&&ok; i++ ){
            if(s[i]=='.'){
                res++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
