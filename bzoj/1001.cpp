/**************************************************************
    Problem: 1001
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:2440 ms
    Memory:133136 kb
****************************************************************/
 
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 4111111, MAXM = 6111111;
bool v[MAXN];
int h[MAXN], d[MAXN], size;
priority_queue<PII, vector<PII>, greater<PII> > q;
struct edge
{
    int p, w, nxt;
    inline edge(int _p = 0, int _w = 0, int _nxt = -1) :
        p(_p), w(_w), nxt(_nxt) {}
} e[MAXM];
inline void addedge(int x, int y, int w)
{
    e[size] = edge(y, w, h[x]);
    h[x] = size ++;
}
inline int getint()
{
    char c;
    while (!isdigit(c = getchar()));
    int ret = c - 48;
    while (isdigit(c = getchar()))
        (ret *= 10) += c - 48;
    return ret;
}
int main()
{
    int n = getint(), m = getint(), t = (n - 1) * (m - 1) * 2 + 1;
    if (n == 1)
    {
        int ans = getint();
        for (int i = 2; i < m; ++ i)
            ans = min(ans, getint());
        printf("%d\n", ans);
        return 0;
    }
    if (m == 1)
    {
        int ans = getint();
        for (int i = 2; i < n; ++ i)
            ans = min(ans, getint());
        printf("%d\n", ans);
        return 0;
    }
    memset(h, -1, sizeof h);
    for (int i = 1; i < m; ++ i)
        addedge(i * 2, t, getint());
    for (int i = 1; i < n - 1; ++ i)
        for (int j = 1; j < m; ++ j)
            addedge(i * (m - 1) * 2 + j * 2, (i - 1) * (m - 1) * 2 + j * 2 - 1, getint());
    for (int i = 1; i < m; ++ i)
        addedge(0, (n - 2) * (m - 1) * 2 + i * 2 - 1, getint());
    for (int i = 0; i < n - 1; ++ i)
    {
        addedge(0, i * (m - 1) * 2 + 1, getint());
        for (int j = 1; j < m - 1; ++ j)
            addedge(i * (m - 1) * 2 + j * 2, i * (m - 1) * 2 + j * 2 + 1, getint());
        addedge((i + 1) * (m - 1) * 2, t, getint());
    }
    for (int i = 0; i < n - 1; ++ i)
        for (int j = 1; j < m; ++ j)
            addedge(i * (m - 1) * 2 + j * 2 - 1, i * (m - 1) * 2 + j * 2, getint());
    memset(d, 63, sizeof d);
    d[0] = 0;
    for (int k = h[0]; k != -1; k = e[k].nxt)
        d[e[k].p] = min(d[e[k].p], e[k].w);
    for (int i = 1; i <= t; ++ i)
        q.push(make_pair(d[i], i));
    v[0] = true;
    for (int i = 2; i < t; ++ i)
    {
        int u = q.top().second;
        for (q.pop(); v[u]; q.pop())
            u = q.top().second;
        v[u] = true;
        for (int k = h[u]; k != -1; k = e[k].nxt)
            if (d[u] + e[k].w < d[e[k].p])
            {
                d[e[k].p] = d[u] + e[k].w;
                q.push(make_pair(d[e[k].p], e[k].p));
            }
    }
    printf("%d\n", d[t]);
    return 0;
}
