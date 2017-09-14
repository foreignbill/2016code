#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int maxn = 1e5 + 5;
int a[maxn];
int st[maxn][25];
int n;

void init(){
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 0; i + (1 << j) - 1 < n; i++){
            st[i][j] = min(st[i + (1 << (j-1))][j - 1], st[i][j - 1]);
        }
    }
}

inline int query(int l, int r){
    int len = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) <= len) k++;
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

inline int solve(){
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    if (l == r) return a[l];
    int val = a[l];
    l++;
    while (l <= r){
        int lb = l, rb = r;
        while (lb < rb){
            int mid = (lb + rb) / 2;
            if (query(lb, mid) <= val) rb = mid;
            else if (query(mid + 1, rb) <= val) lb = mid + 1;
            else return val;
        }
        l = lb + 1;
        val %= a[lb];
    }
    return val;
}

int main(){
	freopen("t.txt","r",stdin);
	freopen("dp.out","w",stdout); 
    int t; scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", a + i);
        }
        init();
        int q; scanf("%d", &q);
        while (q--){
            printf ("%d\n", solve());
        }
    }
    return 0;
}
