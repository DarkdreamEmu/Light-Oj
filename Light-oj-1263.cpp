#include <bits/stdc++.h>
using namespace std;

int money[1010];
vector<int>relation[1010];
int visited[1010];
int cnt;

int dfs(int x){
    if(visited[x])return 0;
    cnt++;
    int sum=money[x];
    visited[x]=1;
    for(int i=0; i<relation[x].size(); i++){
        int v=relation[x][i];
        sum+=dfs(v);
    }
    return sum;
}


int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++){
            scanf("%d",&money[i]);
            relation[i].clear();
            visited[i]=0;
        }
        for(int i=1; i<=m; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            relation[u].push_back(v);
            relation[v].push_back(u);
        }
        bool ok=true;
        set<int>store;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                cnt=0;
                int sum=dfs(i);
                if(sum%cnt){
                    ok=false;
                    break;
                }
                store.insert(sum/cnt);
            }
        }
      //  cout<<store.size()<<endl;
        printf("Case %d: ",cs++);
        if(ok&&store.size()==1)puts("Yes");
        else puts("No");
        store.clear();
    }
    return 0;
}
