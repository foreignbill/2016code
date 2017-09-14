#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 4000000;

bool used[MAX] = {0};
int ki[7], pi[7];
struct Hash{
    int val;
    int count;
};
Hash HashTable[MAX];
int n, m, ans, mid;

int getpow(int x, int p) {
    int tmp = 1;
    while (p) {
        if (p&1)
            tmp *= x;
        x *= x;
        p >>= 1;
    }
    return tmp;
}

int searchHash(int s) {
    int tmp;
    tmp = s;
    while (tmp < 0) tmp += MAX;
    while (tmp >= MAX) tmp -= MAX;
    while (used[tmp] && HashTable[tmp].val != s) {
        tmp++;
        if (tmp >= MAX)
            tmp -= MAX;
    }
    return tmp;
}

void insert(int s) {
    int pos = searchHash(s);
    HashTable[pos].val = s;
    used[pos] = 1;
    HashTable[pos].count++;
}

void leftHalf(int k, int s) {
    int i;
    if (k == mid) {
        insert(s);
        return;
    }
    for (i = 1; i <= m; ++i) {
        leftHalf(k+1,s+ ki[k]*getpow(i, pi[k]));
    }
}

void rightHalf(int k, int s) {
    int i, pos;
    if (k == n) {
        s = -s;
        pos = searchHash(s);
        if (HashTable[pos].val == s)
            ans += HashTable[pos].count;
        return;
    }
    for (i = 1; i <= m; ++i) {
        rightHalf(k+1,s+ki[k]*getpow(i, pi[k]));
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    int i;
    ans = 0;
    mid = n/2;
    for (i = 0; i < n; ++i)
        scanf("%d %d", &ki[i], &pi[i]);
    leftHalf(0, 0);
    rightHalf(mid, 0);
    printf("%d\n", ans);
    return 0;
}