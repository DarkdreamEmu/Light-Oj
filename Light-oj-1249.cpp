#include "bits/stdc++.h"
using namespace std;

struct member{
    string name;
    int L,W,H,volume;
};

bool cmp(member A,member B){
    return A.volume<B.volume;
}

int main(){
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        member take[n+10];
        for(int i=0; i<n; i++){
            cin>>take[i].name;
            scanf("%d %d %d",&take[i].L,&take[i].W,&take[i].H);
            take[i].volume=(take[i].L*take[i].H*take[i].W);
        }
        sort(take,take+n,cmp);
        printf("Case %d: ",cs++);
        if(take[0].volume<take[n-1].volume){
            cout<<take[n-1].name<<" took chocolate from "<<take[0].name<<endl;
        }
        else{
            puts("no thief");
        }
    }
    return 0;
}
