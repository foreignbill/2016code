/*------------------Header Files------------------*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;
/*------------------Definitions-------------------*/
#define LL long long
#define uLL unsigned long long
#define PI acos(-1.0)
#define INF 0x3F3F3F3F
#define MOD 9973
#define MAX 105
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
/*---------------------Work-----------------------*/

void work()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        if(N%2==1)
        {
            printf("Balanced\n");
            continue;
        }
        else
        {
            printf("Bad\n");
        }
    }
}
/*------------------Main Function------------------*/
int main()
{
    //freopen("test.txt","r",stdin);
    work();
    return 0;
}
