#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define N 100000
int tree[N*3],lazy[N*3],input[N];

void make_segment(int node,int beg,int en){
    if(beg==en){
        tree[node]=input[beg];
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beg+en)/2;
    make_segment(left,beg,mid);
    make_segment(right,mid+1,en);
    tree[node]=tree[left]+tree[right];
}

void update_lazy(int node,int beg,int en,int i,int j,int value){
    if(lazy[node]!=0){
        tree[node]+=(en-beg+1)*lazy[node]; // This node needs to be updated
        if(beg!=en){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(beg>en||beg>j||en<i){
        return ;
    }
    if(beg>=i&&en<=j){
        tree[node]+=((en-beg+1)*value);
        if(beg!=en){
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beg+en)/2;
    update_lazy(left,beg,mid,i,j,value);
    update_lazy(right,mid+1,en,i,j,value);
    tree[node]=tree[left]+tree[right];
}

int query_range(int node,int beg,int en,int i,int j){
    if(beg>en||beg>j||en<i){
        return 0;
    }
    if(lazy[node]!=0){
        tree[node]+=(en-beg+1)*lazy[node]; // This node needs to be updated
        if(beg!=en){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(beg>=i&&en<=j){
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beg+en)/2;
    return (query_range(left,beg,mid,i,j)+query_range(right,mid+1,en,i,j));
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            input[i+1]=s[i]-'0';
        }
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        make_segment(1,1,sz);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            char ch;
            scanf(" %c",&ch);
            if(ch=='I'){
                int i,j;
                scanf("%d %d",&i,&j);
                update_lazy(1,1,sz,i,j,1);
            }
            else{
                int ind;
                scanf("%d",&ind);
                printf("%d\n",query_range(1,1,sz,ind,ind)%2);
            }
        }
    }
    return 0;
}
