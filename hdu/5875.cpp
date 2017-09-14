#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
#define lld %I64d
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REPP(i,k,n) for(int i=k;i<=n;i++)
#define scan(d) scanf("%d",&d)
#define scanl(d) scanf("%I64d",&d)
#define scann(n,m) scanf("%d%d",&n,&m)
#define scannl(n,m) scanf("%I64d%I64d",&n,&m)
#define mst(a,k)  memset(a,k,sizeof(a))
#define LL long long
#define N 100005
#define mod 1000000007

const int INF = 0x3f3f3f3f;
int a[N],r[N];
int main()
{
    int T;
    scan(T);
    while(T--)
    {
        int n;
        scan(n);
        REPP(i,1,n) scan(a[i]);
        mst(r,INF);
        for(int i=n-1;i>=1;i--)
        {
            int k = i+1;
            while(1)
            {
                if(a[i]>a[k])
                {
                    r[i] = k;
                    break;
                }
                if(r[k]==INF)
                    break;
                k = r[k];
            }
        }
        int q;
        scan(q);
        while(q--)
        {
            int x,y;
            scann(x,y);
            int ans = a[x];
            x = r[x];
            while(x <= y)
            {
                ans %= a[x];
                if(ans == 0)
                    break;
               x = r[x];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
