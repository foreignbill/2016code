#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define lld %I64d
#define LL long long
#define N 100005
#define mod 1000000007

const int INF = 0x3f3f3f3f;
int a[N],r[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(r,INF,sizeof(r));
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
        scanf("%d",&q);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
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
