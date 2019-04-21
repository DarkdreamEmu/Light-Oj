#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        int n;
        char s[110];
        scanf("%d %s",&n,s);
        printf("Case %d: ",cs++);
        if(strcmp(s,"Alice")==0){
            if(n%3==1)puts("Bob");
            else puts("Alice");
        }
        else{
            if(n%3==0)puts("Alice");
            else puts("Bob");
        }
    }
    return 0;
}
