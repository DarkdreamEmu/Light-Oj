#include "bits/stdc++.h"
using namespace std;

vector<int>G[110],R[110],V;
vector<int>cost[110];
int vis[110],sum=0,last=0;
int t,n;

void dfs(int u,int par){
    if(vis[u])return ;
    vis[u]=1;
    int nisi=1;
    for(int i=0; i<G[u].size(); i++){
        if(nisi==1 && !vis[G[u][i]]){
            nisi++;
            sum=sum+cost[u][i];
            dfs(G[u][i],u);
        }
        else if(nisi==1 && vis[G[u][i]] && last==1 &&par!=G[u][i]){
            sum=sum+cost[u][i];
            last=0;
            nisi++;
            dfs(G[u][i],u);
        }
    }
    for(int i=0; i<R[u].size(); i++){
        if(nisi==1 && !vis[R[u][i]]){
            nisi++;
            last=1;
            dfs(R[u][i],u);
        }
    }
}


int main(){
    int cs=1;
    scanf("%d",&t);
    while(t--){
        int tot=0,ans=0;
        sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(v);
            R[v].push_back(u);
            cost[u].push_back(w);
            tot+=w;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++){
            if(!vis[i] && G[i].size()){
                dfs(i,-1);
            }
        }
        ans=min(tot-sum,sum);
        printf("Case %d: %d\n",cs++,ans);
        V.clear();
        for(int i=0 ;i<=n; i++){
            vis[i]=0;
            G[i].clear();
            R[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
