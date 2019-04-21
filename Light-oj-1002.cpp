#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
#define pii pair<int,int>

struct cmp{
    bool operator()(const pii &A, const pii &B){
        return A.second>B.second;
    }
};

priority_queue< pii, vector<pii> ,cmp> pq;
vector< pii >graph[510];
int dis[510];

void dijkstra(int source,int n){
    for(int i=0; i<n; i++){
        dis[i]=INF;
    }
    dis[source]=0;
    pq.push(make_pair(source,0));
    while(!pq.empty()){
        int u=pq.top().first;
        pq.pop();
        int sz=graph[u].size();
        for(int i=0; i<sz; i++){
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            int mx=max(dis[u],w);
            if(mx<dis[v]){
                dis[v]=mx;
                pq.push(make_pair(v,dis[v]));
            }
        }
    }
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++){
            graph[i].clear();
        }
        for(int i=0; i<m; i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
        }
        int source;
        scanf("%d",&source);
        dijkstra(source,n);
        printf("Case %d:\n",cs++);
        for(int i=0; i<n; i++){
            if(dis[i]==INF){
                printf("Impossible\n");
            }
            else{
                printf("%d\n",dis[i]);
           }
        }
    }
    return 0;
}
