/**Bismillah-ir-Rahman-ir-Rahim**/

#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int n;
char s[14][14],ch;
int dis[15][15];
int visited[15][15];


bool valid(int r,int c){
    return (r>=0&&r<n&&c>=0&&c<n);
}

int bfs(int sr,int sc,int dr,int dc){
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    queue< pair<int,int> >q;
    q.push(make_pair(sr,sc));
    visited[sr][sc]=0;
    dis[sr][sc]=0;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        if(s[r][c]==ch){
            return true;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int R=r+dx[i];
            int C=c+dy[i];
            if(valid(R,C)&&(s[R][C]=='.'||s[R][C]<=ch)&&visited[R][C]==0&&s[R][C]!='#'){
                visited[R][C]=1;
                dis[R][C]=dis[r][c]+1;
                q.push(make_pair(R,C));
            }
        }
    }
    return false;
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int test,cas=1;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        vector< pair<char, pair<int,int> > >store;
        for(int i=0; i<n; i++){
            scanf("%s",s[i]);
            for(int j=0; j<n; j++){
                if(s[i][j]>='A'&&s[i][j]<='Z'){
                    store.push_back(make_pair(s[i][j],make_pair(i,j)));
                }
            }
        }
        sort(store.begin(),store.end());
        int total=0;
        bool ok=true;
       // if(test)printf("\n");
        printf("Case %d: ",cas++);
        if(store.size()==1){printf("0\n");continue;}
        else{
            for(int i=0; i<store.size()-1; i++){
                int start_r=store[i].second.first;
                int start_c=store[i].second.second;
                int end_r=store[i+1].second.first;
                int end_c=store[i+1].second.second;
                ch=store[i+1].first;
                int chk=bfs(start_r,start_c,end_r,end_c);
                if(chk){
                    total+=dis[end_r][end_c];
                }
                else{
                    printf("Impossible\n");
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            printf("%d\n",total);
        }
        store.clear();
    }
    return 0;
}
