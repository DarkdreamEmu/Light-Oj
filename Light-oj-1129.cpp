#include "bits/stdc++.h"
using namespace std;

bool ok;
int cnt=0;
struct node{
    bool endmark;
    int cnt;
    node* next[11];
    node(){
        bool endmark=false;
        cnt=0;
        for(int i=0; i<10; i++){
            next[i]=NULL;
        }
    }
};

void _insert(node* root,string str,int len){
    node* curr=root;
    for(int i=0; i<len; i++){
        int id=(int)(str.at(i)-'0');
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr=curr->next[id];
        ++(curr->cnt);
    }
    curr->endmark=true;
}

int longest_prefix_matching(node* root,string str){
    node* curr=root;
    int len=str.size();
    for(int i=0; i<len; i++){
        int id=(int)(str.at(i)-'0');
        if(curr->next[id]==NULL){
            return 0;
        }
        curr=curr->next[id];
    }
    return curr->cnt;
}

void del(node* curr){
    for(int i=0; i<10; i++){
        if(curr->next[i]){
            del(curr->next[i]);
        }
    }
    delete(curr);
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        node* root=new node();
        ok=true;
        string take[n+10];
        for(int i=0; i<n; i++){
            cin>>take[i];
        }
        sort(take,take+n);
        for(int i=n-1; i>=0&&ok; i--){
            _insert(root,take[i],take[i].size());
            if(longest_prefix_matching(root,take[i])>1)ok=false;
        }
        printf("Case %d: ",cs++)
        if(ok)puts("YES");
        else puts("NO");
        del(root);
    }
    return 0;
}


