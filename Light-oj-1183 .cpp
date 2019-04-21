#include "bits/stdc++.h"
using namespace std;

#define MX 100100
#define LL long long
int input[MX];
int tree[MX*4],lazy[4*MX];

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

void lazy_update(int s,int e,int node_num)
{
  tree[node_num] = (e-s+1) * lazy[node_num];
  if(e>s)
    lazy[node_num*2] = lazy[node_num*2+1] = lazy[node_num];
  lazy[node_num] = -1;
}

void set_lazy(int s,int e,int new_val,int node_num)
{
   if(e>s)
   {
     int m = (s+e)/2;
     lazy[node_num*2] = lazy[node_num*2+1] = new_val;
   }
}
void range_update(int node_num,int s,int e,int l,int r,int new_val)
{
  if(lazy[node_num]!=-1)
    lazy_update(s,e,node_num);
  if(s>r || e<l)
    return;
  else if(s>=l && e<= r)
    tree[node_num] = (e-s+1)*new_val , set_lazy(s,e,new_val,node_num);
  else
  {
    int m = (s+e)/2;
    range_update(node_num*2,s,m,l,r,new_val);
    range_update(node_num*2+1,m+1,e,l,r,new_val);
    tree[node_num] = tree[node_num*2] + tree[node_num*2+1];
  }
}


int query(int node_num,int s,int e,int l, int r)
{
 if(lazy[node_num]!=-1)
    lazy_update(s,e,node_num);
 if(s>r || e<l)
   return 0;
 else if(s>=l && e<=r)
   return tree[node_num];
 else
 {
   int m = (s+e)/2;
   return query(node_num*2,s,m,l,r) + query(node_num*2+1,m+1,e,l,r);
 }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)input[i]=0;
        memset(lazy,-1,sizeof(lazy));
        make_segment(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--){
            int tp;
            scanf("%d",&tp);
            if(tp==1){
                int l,r,val;
                scanf("%d %d %d",&l,&r,&val);
                l++;r++;
                range_update(1,1,n,l,r,val);
            }
            else{
                int l,r;
                scanf("%d %d",&l,&r);
                l++;r++;
                int range=(r-l+1);
                int sum=query(1,1,n,l,r);
                if(sum%range){
                    int num=__gcd(sum,range);
                    printf("%d/%d\n",sum/num,range/num);
                }
                else{
                    printf("%d\n",sum/range);
                }
            }
        }
    }
    return 0;
}
