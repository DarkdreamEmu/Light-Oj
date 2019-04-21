#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
vector<pair<int, pii> >graph;
int parent[110];

void reset(int n){
    for(int i=0; i<=n; i++){
        parent[i]=i;
    }
}

int f_p(int x,int *parent){
    if(x!=parent[x]){
        parent[x]=f_p(parent[x],parent);
    }
    return parent[x];
}

int MST_kruskal_1(int n){
    reset(n);
    int total=0,cnt=0;
    for(int i=0; i<graph.size(); i++){
        int uh=f_p(graph[i].second.first,parent);
        int vh=f_p(graph[i].second.second,parent);
        if(uh!=vh){
            parent[uh]=parent[vh];
            total+=graph[i].first;
            cnt++;
            if(cnt==n){
                break;
            }
        }
    }
    return total;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int u,v,w;
        int e=0;
        while(scanf("%d%d%d",&u,&v,&w)&&(u+v+w)){
            e++;
            graph.push_back(pair<int, pii>(w,pii(u,v)));
        }
        sort(graph.begin(),graph.end());

        int res1=MST_kruskal_1(n);
        reverse(graph.begin(),graph.end());
        int res2=MST_kruskal_1(n);

        int sum=res1+res2;
        //cout<<sum<<endl;
        if(sum%2){
            printf("Case %d: %d/2\n",cs++,sum);
        }
        else{
            printf("Case %d: %d\n",cs++,sum/2);
        }
        graph.clear();
    }
    return 0;
}
