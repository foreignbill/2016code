#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
#define maxn 101
 
struct node
{
    int s, e;
    node *left, *right;
    int num, value, num1;
} tree[maxn * 2], f[maxn];
 
int n, q, ncount;
 
void buildtree(node *proot, int s, int e)
{
    proot->s = s;
    proot->e = e;
    proot->value = -1;
    proot->num = 0;
    if (s == e)
        return;
    ncount++;
    proot->left = tree + ncount;
    ncount++;
    proot->right = tree + ncount;
    buildtree(proot->left, s, (s + e) / 2);
    buildtree(proot->right, (s + e) / 2 + 1, e);
}
 
void init()
{
    int j = 0, a;
    scanf("%d", &f[0].value);
    f[0].num = 1;
    f[0].num1 = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a);
        if (a == f[j].value)
            f[j].num++,f[j].num1++;
        else
        {
            j++;
            f[j].num = 1;
            f[j].num1 = f[j - 1].num1 + 1;
            f[j].value = a;
        }
    }
    n = j;
}
 
void insert(node *proot, node &a, int i)
{
    if (a.num > proot->num)
    {
        proot->num = a.num;
        proot->value = a.value;
    }
    if (proot->s == proot->e)
        return;
    int mid = (proot->s + proot->e) / 2;
    if (i <= mid)
        insert(proot->left, a, i);
    else
        insert(proot->right, a, i);
}
 
void query(node *proot, int i, int j, node &a)
{
    int mid = (proot->s + proot->e) / 2;
    int as, ae;
    if (proot->s == 0)
        as = 1;
    else
        as = f[proot->s - 1].num1 + 1;
    ae = f[proot->e].num1;
    if (i == as && j == ae)
    {
        a.num = proot->num;
        a.value = proot->value;
        return;
    }
    if (proot->s == proot->e)
    {
        a.num = j - i + 1;
        a.value = proot->value;
        return;
    }
    node b, c;
    b.num = 0;
    c.num = 0;
    if (i <= f[mid].num1)
        query(proot->left, i, min(f[mid].num1, j), b);
    if (j > f[mid].num1)
        query(proot->right, max(f[mid].num1 + 1, i), j, c);
    if (b.num > c.num)
    {
        a.num = b.num;
        a.value = b.value;
    }
    else
    {
        a.num = c.num;
        a.value = c.value;
    }
}
 
int main()
{
    //freopen("D:\\t.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n != 0)
    {
        scanf("%d", &q);
        ncount = 0;
        init();
        buildtree(tree, 0, n);
        for (int i = 0; i <= n; i++)
            insert(tree, f[i], i);
        for (int i = 0; i < q; i++)
        {
            int a, b;
            node temp;
            scanf("%d%d", &a, &b);
            query(tree, a, b, temp);
            printf("%d\n", temp.num);
        }
    }
    return 0;
}