#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
const int MAXN = 1e9;
const int N = 200000;
LL num[N];
int main()
{
    int a = 30;
    int b = 19;
    int c = 13;
    int d = 12;
    int t =0;
    for(int i = 0;i<=a;i++)
    {
        for(int j = 0;j<=b;j++)
        {
            for(int k = 0;k<=c;k++)
            {
                for(int q = 0;q<=d;q++)
                {
                    //cout<<"1"<<endl;
                    LL sum = (LL)(pow(2,i)*pow(3,j)*pow(5,k)*pow(7,q));
                    num[t] = sum;
                    t++;
                }
            }
        }
    }
    sort(num,num+t);
    //cout<<t<<endl;
    int cas = 0;
    scanf("%d",&cas);
    while(cas--)
    {
        LL m;
        scanf("%I64d",&m);
        LL res = *(lower_bound(num, num+t, m));
        printf("%I64d\n",res);
    }
    return 0;
}
