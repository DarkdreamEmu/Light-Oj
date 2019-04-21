#include "bits/stdc++.h"
using namespace std;

#define MAX 11000

set< pair<int,int> >AB;
vector<int>G[MAX];
int vis[MAX],dis[MAX],low[MAX],Tm=0,cc[MAX],id[MAX],tot[MAX];

void DFS(int u,int par=-1){
    vis[u]=1;
    dis[u]=low[u]=Tm++;
    int sz=G[u].size();
    for(int i=0; i<sz; i++){
        int v=G[u][i];
        if(v==par)continue;
        if(vis[v]){
            low[u]=min(dis[v],low[u]);
        }
        else{
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(dis[u]<low[v]){
                AB.insert(make_pair(min(u,v),max(u,v)));
            }
        }
    }
}

void Clear(int n){
    for(int i=0; i<=n; i++){
        low[i]=0;
        dis[i]=0;
        vis[i]=0;
        cc[i]=0;
        G[i].clear();
        tot[i]=0;
        id[i]=0;
    }
    AB.clear();
    Tm=0;
}

void dfs(int u,int cnt){
    cc[u]=1;
    id[u]=cnt;
    int sz=G[u].size();
    for(int i=0; i<sz; i++){
        int v=G[u][i];
        if(cc[v])continue;
        if(AB.count(make_pair(min(u,v),max(u,v)))!=0)continue;
        dfs(v,cnt);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        Clear(n);
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0; i<n; i++){
            if(!vis[i])DFS(i);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!cc[i]){
                dfs(i,cnt);
                cnt++;
            }
        }
        set< pair<int,int> >::iterator it=AB.begin();
        while(it!=AB.end()){
            pair<int,int>node=*it;
            tot[ id[node.first] ]++;
            tot[ id[node.second]]++;
            it++;
        }
        int ans=0;
        for(int i=0; i<cnt; i++){
            ans+=(tot[i]==1);
        }
        printf("Case %d: %d\n",cs++,ans/2 + ((ans%2!=0 && ans>=2) ? 1 : 0));
    }
    return 0;
}

