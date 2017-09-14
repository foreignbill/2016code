#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100];

void dfs(int n, ll m) {
    if(n == 0) {puts("b"); return;}
    if(n == 1) {puts("a"); return;}
    ll tmp = f[n];
    if(m >= tmp) dfs(n-2, m-tmp);
    else dfs(n-1, m);
}

int main() {
    int t;
    //freopen("read.in", "r", stdin);
    //freopen("write.out", "w", stdout);
    scanf("%d", &t);
    while(t --) {
        int n;
        ll m;
        scanf("%d%I64d", &n, &m);
        f[0] = 0; f[1] = 1;
        for(int i = 2; i <= n+1; i ++) {
            f[i] = f[i-2] + f[i-1];
        }
        dfs(n, m);
    }
}
