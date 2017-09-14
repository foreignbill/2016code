#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1000005
using namespace std;
int n,m,l,r;
int s[maxn],t[maxn],d[maxn],lim[maxn];
long long tmp[maxn];
inline bool check(int now)
{
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=now;++i) tmp[s[i]]+=d[i],tmp[t[i]+1]-=d[i];
	for (int i=1;i<=n;++i) 
	{
		tmp[i]+=tmp[i-1];
		if (tmp[i]>lim[i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&lim[i]);
	for (int i=1;i<=m;++i) scanf("%d%d%d",&d[i],&s[i],&t[i]);
	r=m+1;
	while(l+1!=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (l==m) printf("0");
	else printf("-1\n%d",r);
	return 0;
}
