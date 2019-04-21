#include <bits/stdc++.h>
using namespace std;

int ar[5];

int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        for(int i=0; i<4; i++){
            cin>>ar[i];
        }
        int q;
        cin>>q;
        printf("Case %d:\n",cs++);
        while(q--){
            int a,b;
            cin>>a>>b;
            if((a>=ar[0]&&a<=ar[2])&&(b<=ar[3]&&b>=ar[1])){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
