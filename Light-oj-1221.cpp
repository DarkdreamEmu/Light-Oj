#include "bits/stdc++.h"
using namespace std;

#define INF 1000000

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        double x1,y1,z1,x2,y2,z2;
        int n;
        scanf("%d",&n);
        double mn_x=INF,mn_y=INF,mn_z=INF,mx_x=0,mx_y=0,mx_z=0;
        while(n--){
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            mx_x=max(x1,mx_x);
            mx_y=max(y1,mx_y);
            mx_z=max(z1,mx_z);

            mn_x=min(mn_x,x2);
            mn_y=min(mn_y,y2);
            mn_z=min(mn_z,z2);
        }
        int res=0;
        if(mn_x>mx_x&&mn_y>mx_y&&mn_z>mx_z){
            res=(mn_x-mx_x)*(mn_y-mx_y)*(mn_z-mx_z);
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}

