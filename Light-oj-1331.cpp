#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        double r1,r2,r3;
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        double a,b,c; //Sides of triangle
        a=r3+r2,b=r1+r3,c=r1+r2;
        double angleA,angleB,angleC; //Angels of triangle
        angleA=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
        angleB=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
        angleC=acos(((b*b)+(a*a)-(c*c))/(2*b*a));
       // cout<<angleA<<" "<<angleB<<" "<<angleC<<endl;
        double area1,area2,area3; //Area of three part of triangle with angle
        area1=(0.5*angleA*r1*r1);
        area2=(0.5*angleB*r2*r2);
        area3=(0.5*angleC*r3*r3);
        //cout<<area1<<" "<<area2<<" "<<area3<<endl;
        double area_total=area1+area2+area3;
        double s=(a+b+c)/2.0;
        double area_of_traingle=sqrt(s*(s-a)*(s-b)*(s-c));
       // cout<<area_of_traingle<<" "<<area_total<<endl;
        printf("Case %d: %.8f\n",cs++,area_of_traingle-area_total);
    }
    return 0;
}
