#include "bits/stdc++.h"
using namespace std;

string S,E;
int N;
map< string, int >D;
set<string>Forbidden;

int bfs(){
    if(Forbidden.find(S)!=Forbidden.end() || Forbidden.find(E)!=Forbidden.end())return -1;
    queue < string >Q;
    Q.push(S);
    D[S]=0;
    while(!Q.empty()){
        string U=Q.front();
        Q.pop();
        if(U==E)return D[U];
        for(int i=0; i<3; i++){
            string tmp=U;
            tmp[i]++;
            if(tmp[i]>'z')tmp[i]='a';
            if(Forbidden.find(tmp)==Forbidden.end() && D[tmp]==0){
                if(tmp==E)return D[U]+1;
                D[tmp]=D[U]+1;
                Q.push(tmp);
            }
            tmp=U;
            tmp[i]--;
            if(tmp[i]<'a')tmp[i]='z';
            if(Forbidden.find(tmp)==Forbidden.end() && D[tmp]==0){
                if(tmp==E)return D[U]+1;
                D[tmp]=D[U]+1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        cin >> S >> E;
        scanf("%d",&N);
        while(N--){
            string a,b,c,tmp="";
            cin >> a >>b >>c;
            for(int i=0; i<a.size(); i++){
                for(int j=0; j<b.size(); j++){
                    for(int k=0; k<c.size(); k++){
                        tmp="abc";
                        tmp[0]=a[i];tmp[1]=b[j];tmp[2]=c[k];
                        Forbidden.insert(tmp);
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++,bfs());
        Forbidden.clear();
        D.clear();
    }
    return 0;
}
