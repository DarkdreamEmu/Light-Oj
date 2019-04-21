#include "bits/stdc++.h"
using namespace std;

struct cor{
    int x,y;
};

bool cmp(cor A,cor B){
    return A.y<B.y;
}

int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        cor take[n+10];
        for(int i=0; i<n; i++){
            scanf("%d %d",&take[i].x,&take[i].y);
        }
        sort(take,take+n,cmp);
        int st=take[0].y;
        int en=st+m;
        int cnt=1;
        for(int i=0; i<n; i++){
            if(take[i].y>=st&&take[i].y<=en){
                continue;
            }
            else{
                st=(take[i].y);
                en=st+m;
                cnt++;
            }
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
