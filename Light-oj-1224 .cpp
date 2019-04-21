#include "bits/stdc++.h"
using namespace std;

int res;
struct node{
    bool endmark;
    int prefixcnt;
    node* next[5];
    node(){
        endmark=false;
        prefixcnt=0;
        for(int i=0; i<5; i++){
            next[i]=NULL;
        }
    }
};

int check(char ch){
    if(ch=='A')return 0;
    if(ch=='C')return 1;
    if(ch=='G')return 2;
    if(ch=='T')return 3;
}

void INSERT(node* root,char* str,int len){
    node* curr=root;
    for(int i=0; i<len; i++){
        int id=check(str[i]);
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr=curr->next[id];
        ++(curr->prefixcnt);
    }
    curr->endmark=true;
}

int ans_me(node* curr,int num){
    for(int i=0; i<5; i++){
        if(curr->next[i]){
            ans_me(curr->next[i],num+1);
        }
    }
    res=max(res,curr->prefixcnt*num);
}

void del(node* curr){
    for(int i=0; i<5; i++){
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
        while(n--){
            char str[1110];
            scanf("%s",&str);
            INSERT(root,str,strlen(str));
        }
        res=0;
        ans_me(root,0);
        printf("Case %d: %d\n",cs++,res);
        del(root);
    }
    return 0;
}
