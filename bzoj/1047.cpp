/**************************************************************
    Problem: 1047
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:700 ms
    Memory:26128 kb
****************************************************************/
 
#include <cctype>
#include <cstdio>
 
const int MAXN = 1111, MAXB = 11111111;
 
char buf[MAXB], *num = buf;
int Q[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN], p[MAXN], q[MAXN];
 
inline void checkmin(int &x, int y){
    if (y < x)
        x = y;
}
 
inline int getint(){
    for (; !isdigit(*num); ++num);
    int ret = *num++ - 48;
    for (; isdigit(*num); (ret *= 10) += *num++ - 48);
    return ret;
}
 
int main(){
    fread(buf, 1, MAXB - 10, stdin);
    int n = getint(), m = getint(), k = getint();
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = 0, f = 1, t = 0;
        for (int j = 1; j <= m; ++j) {
            Q[i][j] = getint();
            for (; l <= r && p[l] + k <= j; ++l);
              for (; l <= r && Q[i][j] > Q[i][p[r]]; --r);
                 p[++r] = j;
            a[i][j] = Q[i][p[l]];
            for (; f <= t && q[f] + k <= j; ++f);
              for (; f <= t && Q[i][j] < Q[i][q[t]]; --t);
                q[++t] = j;
            b[i][j] = Q[i][q[f]];
        }
    }
    int ans = 1000000000;
    for (int j = k; j <= m; ++j) {
        int l = 1, r = 0, f = 1, t = 0;
        for (int i = 1; i < k; ++i) {
            for (; l <= r && a[i][j] > a[p[r]][j]; --r);
            p[++r] = i;
             
            for (; f <= t && b[i][j] < b[q[t]][j]; --t);
            q[++t] = i;
        }
        for (int i = k; i <= n; ++i) {
            for (; l <= r && p[l] + k <= i; ++l);
              for (; l <= r && a[i][j] > a[p[r]][j]; --r);
                p[++r] = i;
                 
            for (; f <= t && q[f] + k <= i; ++f);
              for (; f <= t && b[i][j] < b[q[t]][j]; --t);
                q[++t] = i;
            checkmin(ans, a[p[l]][j] - b[q[f]][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
?
