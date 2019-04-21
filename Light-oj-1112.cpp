#include <bits/stdc++.h>
using namespace std;

#define N 100001
int tree[N*3],input[N];

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

int query(int node,int beg,int en,int i,int j){
    if(beg>=i&&en<=j){
        return tree[node];
    }
    if(beg>j||en<i||beg>en){
        return 0;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beg+en)/2;
    return (query(left,beg,mid,i,j)+query(right,mid+1,en,i,j));
}

void update(int node,int beg,int en,int ind,int newvalue){
    if(ind>en||ind<beg){
        return ;
    }
    if(beg>=ind&&en<=ind){
        tree[node]=input[beg];
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(beg+en)/2;
    update(left,beg,mid,ind,newvalue);
    update(right,mid+1,en,ind,newvalue);
    tree[node]=tree[left]+tree[right];
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&input[i]);
        }
        make_segment(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--){
            int ques;
            scanf("%d",&ques);
            if(ques==1){
                int ind;
                scanf("%d",&ind);
                ind++;
                printf("%d\n",input[ind]);
                input[ind]=0;
                update(1,1,n,ind,0);
            }
            else if(ques==2){
                int ind,val;
                scanf("%d %d",&ind,&val);
                ind++;
                input[ind]+=val;
                update(1,1,n,ind,val);
            }
            else{
                int i,j;
                scanf("%d%d",&i,&j);
                i++;
                j++;
                printf("%d\n",query(1,1,n,i,j));
            }
        }
    }
    return 0;
}
