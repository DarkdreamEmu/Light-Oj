#include "bits/stdc++.h"
using namespace std;

char str[11100];
char line[11111100];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<string,int>MP;
        while(n--){
            scanf("%s",str);
            string s;
            int len=strlen(str);
            s=(string)str;
            if(len>3){
                sort(s.begin()+1,s.end()-1);
            }
            MP[s]++;
        }
        int m;
        scanf("%d",&m);
        printf("Case %d:\n",cs++);
        getchar();
        while(m--){
            long long res=1;
            gets(line);
            string S=(string)line;
            string MM;
            stringstream ss(S);
            while(ss>>MM){
                if(MM.size()>3){
                    sort(MM.begin()+1,MM.end()-1);
                }
                res*=MP[MM];
            }
            printf("%lld\n",res);
        }
        MP.clear();
    }
    return 0;
}
