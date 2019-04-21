#include <bits/stdc++.h>
using namespace std;

#define scanI(a)                            scanf("%d",&a)
#define scanI2(a,b)                         scanI(a) , scanI(b)
#define scanI3(a,b,c)                       scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d)                     scanI(a), scanI(b), scanI(c), scanI(d)
#define FOR(i, a, b)                        for(int i=(a);i<(b);i++)
#define FILL(A,value)                       memset(A,value,sizeof(A))

int fq[27];

int main(){
    int t,cs=1;
    scanI(t);
    getchar();
    while(t--){
        FILL(fq,0);
        char s1[110];
        char s2[110];


        gets(s1);
        int sz=strlen(s1);

        FOR(i,0,sz){
            if(s1[i]!=' '){
                char ch=tolower(s1[i]);
                fq[ch-'a']++;
            }
        }

        gets(s2);
        int sz1=strlen(s2);

        FOR(i,0,sz1){
            if(s2[i]!=' '){
                char ch=tolower(s2[i]);
                fq[ch-'a']--;
            }
        }
        printf("Case %d: ",cs++);
        bool ok=true;
        FOR(i,0,26){
            if(fq[i]!=0){
                ok=false;
                break;
            }
        }
        if(ok){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
