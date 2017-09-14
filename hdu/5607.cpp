#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 100
#define LL long long
using namespace std;
int G[MAXN][MAXN];
const int MOD = 7+1e9;
int n,m;
struct Matrix
{
LL A[MAXN][MAXN];
Matrix()
{
memset(A,0,sizeof(A));
}
};

LL pw(LL a, int k)//a表示数值,ｋ表示多少次方
{
LL t = 1L;
while(k)
{
if(k&1)//如果幂指数为奇数
t = (t * a) %MOD;
a = (a*a)%((LL)MOD);//不管奇偶都做这一步平方
k >>= 1;//ｋ用以二进制表示，每操作一次右移一位
}
return t;
}

Matrix multi(Matrix a,Matrix b,int mod)//两矩阵相乘
{
Matrix t;
for(int i = 1;i <= n;i++)
{
for(int j = 1;j <= n;j++)
{
for(int k = 1;k <= n ;k++)
{
t.A[i][j] = (t.A[i][j]+(a.A[i][k] * b.A[k][j])%mod)%mod;
}
}
}
return t;
}
Matrix pow(Matrix mt , int k , int p)//矩阵快速幂
{
Matrix t;
for(int i = 1 ; i<=n;i++)//单位矩阵
t.A[i][i] = 1;
while(k)
{
if(k&1)//如果幂指数为奇数
t = multi(t , mt , p);
mt =  multi(mt ,mt , p);//不管奇偶都做这一步平方
k >>= 1;
}
return t;
}
int main()
{
int x,y,q,u,k;
scanf("%d%d",&n,&m);
memset(G,0,sizeof(G));
for(int i = 1;i <= m ;i++)
{
scanf("%d%d",&x,&y);
G[x][y]++;
}
for(int i = 1;i <= n ;i++)
{
int s = 0;
for(int j = 1;j<=n;j++)
{
if(G[i][j]==1)
s++;
}
for(int j = 1;j<=n;j++)
{
if(G[i][j]==1)
G[i][j]=s;
}
}
Matrix mt;
for(int i = 1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
mt.A[j][i] = pw((LL)G[i][j],5+1e9);//把初始的矩阵每个元素值乘上5+1e9
}
}
scanf("%d",&q);
while(q--)
{
Matrix mmt = mt;
scanf("%d%d",&u,&k);
mmt =  pow(mmt , k , MOD);
for(int i = 1;i<=n;i++)
//cout<<mt.A[i][u]<<" ";
printf("%I64d ",mmt.A[i][u]);
printf("\n");
}
return 0;
}
