#include "bits/stdc++.h"
using namespace std;

vector<int>G[50010];
int parent[50010],dis[50010],ar[50010],vis[50010];

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
        }
        for(int i=0; i<n-1; i++){
            G[ar[i]].push_back(ar[i+1]);
            G[ar[i+1]].push_back(ar[i]);
        }
        for(int i=0; i<n; i++){
            parent[ar[i]]=-1;
            dis[ar[i]]=0;
            vis[ar[i]]=0;
            sort(G[ar[i]].begin(),G[ar[i]].end());
        }
        int s=ar[0],d=ar[n-1];
        queue<int>Q;
        Q.push(s);
        vis[s]=1;
        parent[s]=-1;
        while(Q.size()){
            int u=Q.front();
            Q.pop();
            int sz=G[u].size();
            if(u==d)break;
            for(int i=0; i<sz; i++){
                int v=G[u][i];
                if(!vis[v]){
                    dis[v]=dis[u]+1;
                    vis[v]=1;
                    parent[v]=u;
                    Q.push(v);
                }
            }
        }
        printf("Case %d:\n",cs++);
        vector<int>path;
        for(int v=d; v!=-1; v=parent[v]){
            path.push_back(v);
        }
        for(int i=path.size()-1; i>=0; i--){
            printf("%d",path[i]);
            if(i!=0)printf(" ");
        }
        printf("\n");
        for(int i=0; i<n; i++)G[ar[i]].clear();
    }
    return 0;
}
