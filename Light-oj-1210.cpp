#include "bits/stdc++.h"
using namespace std;

#define MAX 20010

vector<int>G[MAX],R[MAX],topo;
int V[MAX],SCC[MAX],N,M;
int Ind[MAX],Out[MAX];

void dfs1(int u){
    V[u]=1;
    int sz=G[u].size();
    for(int i=0; i<sz; i++)if(!V[G[u][i]])dfs1(G[u][i]);
    topo.push_back(u);
}

void dfs2(int u,int Num){
    V[u]=1;
    SCC[u]=Num;
    int sz=R[u].size();
    for(int i=0; i<sz; i++)if(!V[R[u][i]])dfs2(R[u][i],Num);
}

void Clean(){
    for(int i=0; i<=N; i++){
        G[i].clear();
        R[i].clear();
        V[i]=0;
        Ind[i]=0;
        Out[i]=0;
        SCC[i]=-1;
    }
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        Clean();
        topo.clear();
        scanf("%d %d",&N,&M);
        for(int i=0; i<M; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            G[u-1].push_back(v-1);
            R[v-1].push_back(u-1);
        }
        for(int i=0; i<N; i++){
            if(!V[i])dfs1(i);
        }
        memset(V,0,sizeof(V));
        int sz=topo.size();
        int in=0,out=0,Num=1;
        for(int i=sz-1; i>=0; i--){
            if(!V[topo[i]]){
                dfs2(topo[i],Num);
                Num++;
            }
        }
        for(int i=0; i<N; i++){
            sz=G[i].size();
            for(int j=0; j<sz; j++){
                if(SCC[i]!=SCC[G[i][j]]){
                    Ind[SCC[G[i][j]]]++;
                    Out[SCC[i]]++;
                }
            }
        }
        for(int i=1; i<Num; i++){
            if(!Ind[i])in++;
            if(!Out[i])out++;
        }
        if(N==1||(Num-1)==1)in=0,out=0;
        printf("Case %d: %d\n",cs++,max(in,out));
    }
    return 0;
}

