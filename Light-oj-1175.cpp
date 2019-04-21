#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define MAX 100000

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

char matrix[1010][1010];
int dis[1010][1010];
int f[1010][1010];
int r,c;

void clean(){
    for(int i=0; i<1010; i++){
        for(int j=0; j<1010; j++){
            dis[i][j]=MAX;
            f[i][j]=MAX;
        }
    }
}

bool valid(int R,int C){
    return ((R>=0&&R<r)&&(C>=0&&C<c));
}

void bfs(int sr,int sc){
    queue<pii>q;
    q.push(pii(sr,sc));
    dis[sr][sc]=0;
    int cnt=0,side=0;
    while(!q.empty()){
        pii tak=q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int R=tak.first+dx[k];
            int C=tak.second+dy[k];
            if(dis[R][C]==MAX&&valid(R,C)&&matrix[R][C]!='#'){
                dis[R][C]=dis[tak.first][tak.second]+1;
                q.push(pii(R,C));
            }
        }
    }
}

void fire(){
    queue<pii>q;
    for ( int i = 0; i < r; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            if ( matrix [i] [j] == 'F' ) {
                f [i] [j] = 0;
                q.push(pii (i, j));
            }
        }
    }
    while(!q.empty()){
        pii tak=q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int R=tak.first+dx[k];
            int C=tak.second+dy[k];
            if(matrix[R][C]!='#'&&(f[R][C]==MAX)&&valid(R,C)){
                f[R][C]=f[tak.first][tak.second]+1;
                q.push(pii(R,C));
            }
        }
    }
}

int main(){

	////freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int fr,fc,sr,sc;
        scanf("%d%d",&r,&c);
        for(int i=0; i<r; i++){
        	getchar();
            for(int j=0; j<c; j++){
            	scanf("%c",&matrix[i][j]);
            	if(matrix[i][j]=='J'){
            		sr=i;
            		sc=j;
				}
			}
        }
        clean();
        bfs(sr,sc);
        fire();
        int mn=MAX;
        for(int i=0; i<r; i++){
            if(f[i][0]>dis[i][0]){
                mn=min(mn,dis[i][0]);
            }
            if(f[i][c-1]>dis[i][c-1]){
                mn=min(mn,dis[i][c-1]);
            }
        }
        for(int j=0; j<c; j++){
            if(f[0][j]>dis[0][j]){
                mn=min(mn,dis[0][j]);
            }
            if(f[r-1][j]>dis[r-1][j]){
                mn=min(mn,dis[r-1][j]);
            }
        }
        printf("Case %d: ",cs++);
        if(mn==MAX){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",mn+1);
        }
    }
    return 0;
}
