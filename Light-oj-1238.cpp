#include <bits/stdc++.h>
using namespace std;

int row,col,dr,dc;
char s[30][30];
int visited[30][30];
int dis[30][30];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int r,int c){
    if(r>=0&&r<row&&c>=0&&c<col&&(s[r][c])!='m'&&s[r][c]!='#')return true;
    else return false;
}


int bfs(int sr,int sc){
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    queue< pair<int,int> >q;
    q.push(make_pair(sr,sc));
    visited[sr][sc]=1;
    dis[sr][sc]=0;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        if(r==dr&&c==dc){
            return dis[dr][dc];
        }
        q.pop();
        for(int i=0; i<4; i++){
            int R=r+dx[i];
            int C=c+dy[i];
            if(!visited[R][C]&&valid(R,C)){
                visited[R][C]=1;
                dis[R][C]=dis[r][c]+1;
                q.push(make_pair(R,C));
            }
        }
    }
}

int main(){
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        vector< pair<int,int> >position;
        scanf("%d %d",&row,&col);
        for(int i=0; i<row; i++){
            scanf("%s",s[i]);
            for(int j=0; j<col; j++){
                if(s[i][j]=='a'||s[i][j]=='b'||s[i][j]=='c'){
                    position.push_back(make_pair(i,j));
                }
                if(s[i][j]=='h'){
                    dr=i;
                    dc=j;
                }
            }
        }
        int res=bfs(position[0].first,position[0].second);
        res=max(res,bfs(position[1].first,position[1].second));
        res=max(res,bfs(position[2].first,position[2].second));
        printf("Case %d: %d\n",cs++,res);
        position.clear();
    }
    return 0;
}
