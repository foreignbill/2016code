#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int bit[100100];
int n;

int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= i & - i;
    }
    return s;
}
void add(int i, int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += i & - i;
    }
}

int main()
{	freopen("t.txt","r",stdin);
	freopen("t2.out","w",stdout); 
    int a, b;
    while(scanf("%d", &n), n)
    {
        memset(bit, 0, sizeof bit);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            add(a, 1);
            add(b + 1, -1);
        }
        for(int i = 1; i <= n; i++)
            if(i == n) printf("%d\n", sum(i));
            else printf("%d ", sum(i));
    }

    return 0;
}

