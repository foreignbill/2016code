#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 1005
int dp[MAXN][MAXN];
char s1[MAXN], s2[MAXN];
char ch1[2], ch2[2];
bool HASH[128][128];
int Max(int a, int b){
    return (a > b) ? a : b;
}
int main()
{
    int T;
    int cas = 0;
    for(scanf("%d", &T); T--; )
    {
        scanf("%s%s", s1 + 1, s2 + 1);
        int m;
        scanf("%d", &m);
        memset(HASH, 0, sizeof(HASH));
        while(m--)
        {
            scanf("%s%s", ch1, ch2);
            HASH[ch1[0]][ch2[0]] = 1;
        }
        int len1 = strlen(s1 + 1);
        int len2 = strlen(s2 + 1);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len2; ++i)
        {
            for(int j = 1; j <= len1; ++j)
            {
                dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
                if((s2[i] == s1[j]) || (HASH[s2[i]][s1[j]]))
                    dp[i][j] = Max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        if(dp[len2][len1] == len1)
            printf("Case #%d: happy\n", ++cas);
        else
            printf("Case #%d: unhappy\n", ++cas);
    }
    return 0;
}
