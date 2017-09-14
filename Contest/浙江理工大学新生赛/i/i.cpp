#include <stdio.h>

int main()
{
    int T;
    int m,n,k;
    scanf("%d",&T);
    for (int i = 0 ; i < T;i++)
    {
        scanf("%d %d %d",&n,&m,&k);
        if (n % m == 0)
        {
            printf("YES\n");
            continue;
        }
        else
        {
            int j = n / m;
            if ((n+k) >= (j+1)*m )
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}

