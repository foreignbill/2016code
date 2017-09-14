#include<stdio.h>
#include<math.h>

int main()
{
    long long n;
    while (scanf("%d",&n)!=EOF) 
    {
        int x=(int)(sqrt(n));
        if (x*x==n) printf("1\n");
        else printf("0\n");
        
    }
    return 0;
} 
