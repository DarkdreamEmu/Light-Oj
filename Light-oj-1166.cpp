#include <bits/stdc++.h>
using namespace std;

int a[110],b[110];

int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            int tm;
            scanf("%d",&tm);
            a[i]=tm;
            b[i]=tm;
        }
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]!=i)
            {
                for(int j=i+1; j<=n; j++)
                {
                    if(a[j]==i)
                    {
                        swap(a[i],a[j]);
                        cnt++;
                    }
                }
            }
        }
        printf("Case %d: %d\n",c++,cnt);
    }
    return 0;
}
