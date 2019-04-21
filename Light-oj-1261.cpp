#include "bits/stdc++.h"
using namespace std;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        vector<int>choice[40];
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                int num;
                scanf("%d",&num);
                choice[i].push_back(num);
            }
        }
        int st;
        scanf("%d",&st);
        vector<int>V;
        for(int i=0; i<st; i++){
            int num;
            scanf("%d",&num);
            V.push_back(num);
        }
        sort(V.begin(),V.end());
        bool ok=true;
        int take[40],con[40],Not[40];
        for(int i=0; i<=30; i++){
                take[i]=con[i]=Not[i]=0;
        }
        for(int i=0; i<n; i++){
            int sz=choice[i].size();
            for(int j=0; j<sz; j++){
                int num=choice[i][j];
                if( num>0 && binary_search(V.begin(),V.end(),num)) take[i]=1;
                else if(num<0 && binary_search(V.begin(),V.end(),abs(num))) con[i]=1;
                else if (num<0 && !binary_search(V.begin(),V.end(),abs(num))) Not[i]=1;
                else continue;
            }
        }
        printf("Case %d: ",cs++);
        for(int i=0; i<n; i++){
            if(take[i])continue;
            if(con[i] && !Not[i]){
                ok=false;
                break;
            }
            if(!con[i] && !Not[i] &&!take[i])ok=false;
        }
        if(ok)puts("Yes");
        else puts("No");
        //cout<<st<<endl;
        for(int i=0; i<=40; i++)choice[i].clear();
    }
    return 0;
}
