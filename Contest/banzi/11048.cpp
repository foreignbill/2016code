/**************************************************************
    Problem: 1048
    User: pikapika
    Language: C++
    Result: Accepted
    Time:104 ms
    Memory:1788 kb
****************************************************************/
 
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
const int INF = (int)(1e9) + 10;
 
const int N = 10 + 2;
int d[N][N][N][N][N];//x1,y1,x2,y2,lim
 
int r, c, lim;
 
int ar[N][N];
int sum(int x1, int y1, int x2, int y2) {
    int re = 0;
    for (int i = x1; i <= x2; ++i)
        for (int j = y1; j <= y2; ++j)
            re += ar[i][j];
    return re * re;
}
int dp(int x1, int y1, int x2, int y2, int ti) {
    int& z = d[x1][y1][x2][y2][ti];
    if (~z) return z;
    if (1 == ti) {
        return z = sum(x1, y1, x2, y2);
    }
    z = INF;
    for (int i = x1; i < x2; ++i)
        for (int j = 1; j < ti; ++j)
            z = std::min(z, dp(x1, y1, i, y2, j) + dp(i + 1, y1, x2, y2, ti - j));
    for (int i = y1; i < y2; ++i) {
        for (int j = 1; j < ti; ++j)
            z = std::min(z, dp(x1, y1, x2, i, j) + dp(x1, i + 1, x2, y2, ti - j));
    }
    return z;
}
void work() {
    int tot = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            scanf("%d", &ar[i][j]);
            tot += ar[i][j];
        }
    memset(d, -1, sizeof(d));
 
    int mx = dp(1, 1, r, c, lim);
    //printf("%d\n", mx);
 
    double avg = (double)tot / lim;
    double ans = std::sqrt((double)mx / lim - 2. * avg * tot / lim + avg * avg);
    printf("%.2f\n", ans);
}
int main() {
	freopen("d.in","r",stdin); 
    while (3 == scanf("%d%d%d", &r, &c, &lim)) {
        work();
    }
    return 0;
}
