#include <bits/stdc++.h>
using namespace std;

#define scanI(a)                            scanf("%d",&a)
#define FOR(i, a, b)                        for(int i=(a);i<(b);i++)


int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};


char s[50][50];
bool visited[50][50];
int res=1;
int w,h;

bool valid(int i,int j){
    return ((i>=0&&i<h)&&(j>=0&&j<w));
}

void dfs(int i,int j){
    visited[i][j]=1;
    s[i][j]='#';
    FOR(k,0,4){
        int R=dx[k]+i;
        int C=dy[k]+j;
        if(!visited[R][C]&&s[R][C]!='#'&&valid(R,C)){
            res++;
            dfs(R,C);
        }
    }
}

int main(){
    int t,c=1;
    scanI(t);
    while(t--){
        scanI(w);
        scanI(h);
        FOR(i,0,h){
            FOR(j,0,w){
                visited[i][j]=0;
            }
        }
        int pos1=0,pos2=0;
        FOR(i,0,h){
            FOR(j,0,w){
                cin>>s[i][j];
                if(s[i][j]=='@'){
                    pos1=i;
                    pos2=j;
                }
            }
        }
        dfs(pos1,pos2);
        printf("Case %d: %d\n",c++,res);
        res=1;
    }
    return 0;
}
