#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int inf=(1<<30)-1;
const int maxn=1000010;
#define REP(i,n) for(int i=(0);i<(n);i++)
#define FOR(i,j,n) for(int i=(j);i<=(n);i++)
typedef long long ll;
int a[maxn];
int dp[maxn];
int main()
{
	freopen("input.txt","r",stdin);
    int n,T;
    scanf("%d",&T);
    while(scanf("%d",&n),T--)
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[n]=a[n];
        for(int i=n-1;i>=1;i--)
        {
            dp[i]=a[i];
            dp[i]=min(dp[i],dp[i+1]);
        }
        int ans=1,Max=-inf;
        for(int i=1;i<=n;i++)
        {
            Max=max(Max,a[i]);
            if(dp[i+1]>=Max)
                ans++;
            //printf("*%d*\n",ans);
        }
        printf("%d\n",ans);
        if(T!=0)puts("");
    }
    return 0;
}
