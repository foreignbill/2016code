#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define LL long long
const int MOD = 1E9 + 7;
struct Node
{
    LL cnt;
    LL sum;
    LL sqsum;
    Node(){}
    Node(LL a, LL b, LL c):cnt(a), sum(b), sqsum(c){}
}dp[20][7][7];
int dis[20];
LL c[20];

Node dfs(int len, int pra, int prb, bool flag)
{
    if(len < 0)
    {
        return Node(pra!=0 && prb!=0, 0, 0);
    }
    if(!flag && dp[len][pra][prb].cnt != -1)
        return dp[len][pra][prb];
    int end = flag?dis[len]:9;
    Node ans = Node(0, 0, 0);
    for(int i=0; i<=end; i++)
    {
        if(i != 7)
        {
            Node t = dfs(len-1, (pra+i)%7, (prb*10+i)%7, flag && i==end);
            ans.cnt = (ans.cnt + t.cnt) % MOD;
            ans.sum += (((c[len]*i)%MOD*t.cnt)%MOD + t.sum) % MOD;
            ans.sum %= MOD;
            ans.sqsum += (t.sqsum + ((2*c[len]*i)%MOD*t.sum)%MOD) %MOD;
            ans.sqsum %= MOD;
            ans.sqsum += ((i*c[len]*i%MOD)*c[len]%MOD * t.cnt) %MOD;
            ans.sqsum %= MOD;
        }
    }
    if(!flag)
        dp[len][pra][prb] = ans;
    return ans;
}

void init()
{
    c[0] = 1;
    for(int i=1; i<20; i++)
        c[i] = (c[i-1]*10) % MOD;
}

LL solve(LL n)
{
    int len = 0;
    while(n)
    {
        dis[len++] = n%10;
        n /= 10;
    }
    Node ans;
    ans = dfs(len-1, 0, 0, 1);
    return ans.sqsum;
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    memset(dp, -1, sizeof(dp));
    while(T--)
    {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (solve(r) - solve(l-1) + MOD) % MOD);
    }
    return 0;
}
