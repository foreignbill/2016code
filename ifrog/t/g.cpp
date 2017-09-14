#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int inf=1e9;
const int N=200002;
int n,k,T,a[N],q[N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]+=a[i-1];
        }
        for(int i=n+1;i<n+k;i++)
            a[i]=a[n]+a[i-n];
        int m=n+k-1;
        int head=0,tail=0;
        int maxx=-inf;
        int l,r;
        for(int i=1;i<=m;i++)
        {
            while(head<tail&&a[i-1]<a[q[tail-1]])
                tail--;
            q[tail++]=i-1;
            while(head<tail&&i-q[head]>k)
                  head++;
            if(maxx<a[i]-a[q[head]])
            {
                maxx=a[i]-a[q[head]];
                l=q[head]+1;
                r=i>n?i%n:i;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}

