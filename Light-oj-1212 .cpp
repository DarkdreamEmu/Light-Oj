#include "bits/stdc++.h"
using namespace std;

deque<int>D;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int N,M;
        scanf("%d %d",&N,&M);
        D.clear();
        printf("Case %d:\n",cs++);
        while(M--){
            string s;
            int num;
            cin>>s;;
            if(s=="pushLeft"){
                cin>>num;
                if(D.size()!=N)D.push_front(num),printf("Pushed in left: %d\n",num);
                else printf("The queue is full\n");
            }
            else if(s=="pushRight"){
                cin>>num;
                if(D.size()!=N)D.push_back(num),printf("Pushed in right: %d\n",num);
                else printf("The queue is full\n");
            }
            else if(s=="popLeft"){
                if(!D.empty())printf("Popped from left: %d\n",D.front());
                else printf("The queue is empty\n");
                if(D.size())D.pop_front();
            }
            else if(s=="popRight"){
                if(!D.empty())printf("Popped from right: %d\n",D.back());
                else printf("The queue is empty\n");
                if(D.size())D.pop_back();
            }
        }
    }
    return 0;
}
