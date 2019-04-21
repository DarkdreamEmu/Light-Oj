#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int>vec;
        for(int i=0; i<n; i++){
            int num;
            scanf("%d",&num);
            vec.push_back(num);
        }
        int mul=0,div=0,add=0,rev=0;
        while(m--){
            char ch;
            int a,b;
            scanf(" %c",&ch);
            if(ch=='P'){
                scanf("%d %d",&a,&b);
                swap(vec[a],vec[b]);
            }
            else if(ch!='R'){
                scanf("%d",&a);
                if(ch=='S'){
                    for(int i=0; i<n; i++){
                        vec[i]+=a;
                    }
                }
                else if(ch=='M'){
                    for(int i=0; i<n; i++){
                        vec[i]*=a;
                    }
                }
                else{
                    for(int i=0; i<n; i++){
                        vec[i]/=a;
                    }
                }
            }
            else{
                reverse(vec.begin(),vec.end());
            }
        }
        printf("Case %d:\n",cs++);
        for(int i=0; i<n; i++){
            printf("%d",vec[i]);
            if(i<n-1)printf(" ");
        }
        printf("\n");
        vec.clear();
    }
    return 0;
}
