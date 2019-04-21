#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int x1,y1,r1,x2,y2,r2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        double distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        double res=0;
        int r=r1,R=r2;
        if(distance>=r1+r2)res=0;
        else if(r1+r2>=distance && abs(r1-r2)<distance){
            if(r>R)swap(r,R);
            double first=(r*r)*acos(((distance*distance)+(r*r)-(R*R))/(2*distance*r));
            double second=(R*R)*acos(((distance*distance)+(R*R)-(r*r))/(2*distance*R));
            double third=sqrt((-distance+r+R)*(distance+r-R)*(distance-r+R)*(distance+r+R));
            res=first+second-(.5*third);
        }
        else{
            res=min(r,R);
            res=res*res*acos(-1.0);
        }
        printf("Case %d: %.9f\n",cs++,res);
    }
    return 0;
}
