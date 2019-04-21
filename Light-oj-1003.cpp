#include <bits/stdc++.h>
using namespace std;

#define FILL(A,value)                       memset(A,value,sizeof(A))
#define FOR(i, a, b)                        for(int i=(a);i<(b);i++)
#define PB                                  push_back


vector<int> graph[100100];
int visited[100100];
int cycle=0;

void dfs(int u){
    if(visited[u]==2||cycle){
        return ;
    }
    if(visited[u]==1){
        cycle=1;
        return ;
    }
    visited[u]=1;
    int siz=graph[u].size();
    FOR(i,0,siz){
        dfs(graph[u][i]);
    }
    visited[u]=2;
}

int main(){
    map<string,int>index;
    int m,c=1;
    int t;
    cin>>t;
    while(t--){
        FILL(visited,0);
        cin>>m;
        int id=1;
        FOR(i,0,m){
            string u,v;
            cin>>u>>v;
            if(!index[u]){
                index[u]=id++;
            }
            if(!index[v]){
                index[v]=id++;
            }
            graph[index[u]].PB(index[v]);
        }
        FOR(i,1,id+1){
            dfs(i);
        }
        if(cycle){
            printf("Case %d: No\n",c++);
        }
        else{
            printf("Case %d: Yes\n",c++);
        }
        cycle=0;
        FOR(i,1,id+1){
            graph[i].clear();
        }
        index.clear();
    }
    return 0;
}

