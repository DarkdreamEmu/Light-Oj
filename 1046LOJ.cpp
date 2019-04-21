#include "bits/stdc++.h"
using namespace std;

int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

char s[30][30];
int dis[30][30],vis[30][30];
int n,m,ans,cnt,dr,dc,tot=0,sum=0;
bool ok=true;

struct node{
    int r,c,type;
}store[200];

bool valid(int r,int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

void bfs(node take){
    memset(dis,0,sizeof(dis));
    queue< node >Q;
    Q.push(take);
    while(Q.size()){
        int sr=Q.front().r,sc=Q.front().c,jump=Q.front().type;
        Q.pop();
        if(sr==dr && sc==dc){
            tot++;
            sum+=(dis[sr][sc]/jump)+(dis[sr][sc]%jump==0 ? 0 :1);
            return ;
        }
        for(int i=0; i<8; i++){
            int curR=dx[i]+sr;
            int curC=dy[i]+sc;
            if(valid(curR,curC) && !dis[curR][curC]){
                dis[curR][curC]=dis[sr][sc]+1;
                Q.push({curR,curC,jump});
            }
        }
    }
}

void solve(){
    ok=true;
    ans=INT_MAX,cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]!='.'){
                store[cnt++]={i,j,(int)(s[i][j]-'0')};
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dr=i;
            dc=j;
            tot=0;
            sum=0;
            for(int k=0; k<cnt; k++){
                if(ok)bfs(store[k]);
                else break;
            }
            if(tot==cnt){
                ans=min(ans,sum);
            }
        }
    }
    if(ans==INT_MAX)ans=-1;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)scanf("%s",&s[i]);
        solve();
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
