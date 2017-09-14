#include <iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
char c[110000];
__int64 getsum(__int64 n)   //等差数列前n项和
{
    if(n%2==0)return n/2*(1+n);
    else return (1+n)/2*n;
}
int main()
{
	freopen("d.in","r",stdin); 
	freopen("d1.txt","w",stdout); 
    int n;
    scanf("%d%*c",&n);
    while(n--)
    {
        __int64 sum=0,s=0;
        gets(c);
        for(__int64 i=0; i<(__int64)strlen(c); i++)
        {
            if(c[i]=='q')s++;
            else
            {
                if(s)sum+=getsum(s);
                s=0;
            }
        }
        printf("%I64d\n",sum+getsum(s));
    }
    return 0;
}
