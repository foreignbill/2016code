#include <bits/stdc++.h>
#define M 200005
#define inf 0x3fffffff
using namespace std;
int q[M],sum[M];
int main(){
    int T, n, k, i;
    scanf("%d", &T);
    while (T--){
        scanf ("%d%d", &n, &k);
        for (i = 1; i <= n; i++) scanf ("%d", sum+i);
        for (i = n+1; i <= n+k-1; i++) sum[i] = sum[i-n];
        for (i = 2; i <= n+k-1; i++) sum[i] += sum[i-1];//处理前缀和 
        int head = 0, tail = 0, maxs = -inf, a,  b;
        for (i = 1; i <= n+k-1; i++){
            while (tail > head && (sum[i-1] - sum[q[tail - 1] - 1])< 0) tail--;
            q[tail++] = i;
            int tp = sum[i]-sum[q[head]-1] ;
            if (tp > maxs){
                maxs = tp;
                a = q[head];
                b = i;
            }
            while (tail > head && i - q[head] + 1 >= k) head++;
        }
        if (b > n) b -= n;
        printf ("%d %d %d\n",maxs,a,b);
    }
    return 0;
}
