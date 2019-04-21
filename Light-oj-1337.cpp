#include "bits/stdc++.h"
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

char S[510][510];
int ROW,COL,Q;
int V[510][510];
int res[510*510];

bool valid(int r,int c){
    return ( (r>=0&&r<ROW) && (c>=0&&c<COL) );
}

void dfs(int r,int c,int cnt){
    V[r][c]=cnt;
    for(int i=0; i<4; i++){
        int R=r+dx[i];
        int C=c+dy[i];
        if(valid(R,C) && S[R][C]=='C' && !V[R][C])res[cnt]++,dfs(R,C,cnt);
        else if(valid(R,C) && S[R][C]=='.' &&!V[R][C])dfs(R,C,cnt);
        else continue;
    }
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&ROW,&COL,&Q);
        for(int i=0; i<ROW; i++)scanf("%s",S[i]);
        memset(V,0,sizeof(V));
        memset(res,0,sizeof(res));
        int cnt=0;
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(!V[i][j] && S[i][j]=='.'){
                    cnt++;
                    dfs(i,j,cnt);
                }
                else if(!V[i][j]&&S[i][j]=='C'){
                    cnt++;
                    V[i][j]=cnt;
                    res[cnt]++;
                    dfs(i,j,cnt);
                }
            }
        }
        printf("Case %d:\n",cs++);
        while(Q--){
            int sr,sc;
            scanf("%d %d",&sr,&sc);
            sr--,sc--;
            if(S[sr][sc]=='C' && V[sr][sc]==0)puts("1");
            else printf("%d\n",res[V[sr][sc]]);
        }
    }
    return 0;
}

