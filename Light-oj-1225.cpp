#include <stdio.h>
int main()
{
    int test, i, n, rem, temp;
    scanf("%d", &test);

    for (i=1; i<=test; i++)
    {
        int reverse=0;
        scanf("%d" , &n);
        temp=n;

        while( temp!=0 )
        {
            rem=temp%10;
            reverse=reverse*10+rem;
            temp/=10;
        }
        if( reverse==n )
            printf ("Case %d: Yes\n", i);
        else
            printf ("Case %d: No\n", i);
    }
    return 0;
}
