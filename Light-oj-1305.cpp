#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        double Ax, Ay, Bx, By, Cx, Cy;
        cin>>Ax >> Ay >> Bx >> By >> Cx >> Cy;
        double Dx,Dy;
        Dx=Ax+Cx-Bx;
        Dy=Ay+Cy-By;
        double area = ((Ax*By)+(Bx*Cy)+(Cx*Dy)+(Dx*Ay))-((Ay*Bx)+(By*Cx)+(Cy*Dx)+(Dy*Ax));
        printf("Case %d: %.f %.f %.f\n",cs++,Dx,Dy,abs(area/2));
    }
    return 0;
}
