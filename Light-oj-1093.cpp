#include "bits/stdc++.h"
using namespace std;

#define MX 100100
int input[MX],Tmn[MX*3],Tmx[MX*3];

void Build(int node,int L,int R){
    if(L==R){
        Tmn[node]=Tmx[node]=input[L];
        return ;
    }
    int mid=(L+R)/2;
    Build(node*2,L,mid);
    Build(node*2+1,mid+1,R);
    Tmn[node]=min(Tmn[node*2],Tmn[node*2+1]);
    Tmx[node]=max(Tmx[node*2],Tmx[node*2+1]);
}


int querymn(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 1000000000;
    if (b >= i && e <= j)
        return Tmn[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = querymn(Left, b, mid, i, j);
    int p2 = querymn(Right, mid + 1, e, i, j);
    return min(p1 , p2);
}
int querymx(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return -1000000000;
    if (b >= i && e <= j)
        return Tmx[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = querymx(Left, b, mid, i, j);
    int p2 = querymx(Right, mid + 1, e, i, j);
    return max(p1 , p2);
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1; i<=n; i++){
            scanf("%d",&input[i]);
        }
        Build(1,1,n);
        int res=-INT_MAX;
        for(int i=1; i<=n; i++){
            int range=i+d-1;
            res=max(querymx(1,1,n,i,range)-querymn(1,1,n,i,range),res);
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
