#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
int n,m,x,y,z,l,s,u,v,q;
bool vis[10010];
struct point{
	int x,y,z;
}a[50010];
struct node{
	int y,z,next;
}edge[500010];
int father[50010],deep[50010],head[50010];
int f[50010][20],g[50010][20];
int cmp(point a,point b)
{
	return a.z<b.z;
}
int find(int x)
{
	if (father[x]!=x)
		father[x]=find(father[x]);
	return father[x];
}
void add(int x,int y,int z)
{
	l++;
	edge[l].y=y;edge[l].z=z;
	edge[l].next=head[x];
	head[x]=l;
}
void dfs(int x)
{
    vis[x]=1;
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		if (vis[edge[i].y]==0)
		{
			deep[edge[i].y]=deep[x]+1;
			f[edge[i].y][0]=x;
			g[edge[i].y][0]=edge[i].z;
			dfs(edge[i].y);
		}
	}
}
void dp()
{
	for (int j=1;j<=15;j++)
		for (int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
		}
}
int lca(int x,int y)
{
	int t,ans=INF;
	if (find(x)!=find(y)) return -1;
	if (deep[x]>deep[y])
	{
		t=x;x=y;y=t;
	}
		for (int i=15;i>=0;i--)
		  if (deep[f[y][i]]>=deep[x])
		  {
			  ans=min(ans,g[y][i]);
			  y=f[y][i];
		  }
    if (x==y) return ans;
	    for (int i=15;i>=0;i--)
	 	 if (f[x][i]!=f[y][i])
		 {
		    ans=min(ans,g[x][i]);
			 ans=min(ans,g[y][i]);
			x=f[x][i];
			y=f[y][i];
		 }

    ans=min(ans,g[x][0]);
	ans=min(ans,g[y][0]);
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d%d", &n, &m ,&q);
		for (int i=1;i<=m;i++)
	        scanf("%d%d%d",&a[i].x, &a[i].y, &a[i].z);
		sort(a+1,a+m+1,cmp);
		for (int i=1;i<=n;i++) father[i]=i;
		s=0;
		memset(head,0,sizeof(head));
		for (int i=1;i<=m;i++){
		    u=find(a[i].x);
			v=find(a[i].y);
			if (u!=v){
				s++;
				father[u]=father[v];
				add(a[i].x,a[i].y,a[i].z);
				add(a[i].y,a[i].x,a[i].z);
			}
			if (s==n-1) break;
		}
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
	    memset(g,0,sizeof(g));
		for (int i=1;i<=n;i++){
			if (!vis[i]){
				deep[i]=1;
				dfs(i);
			}
		}
		dp();
		while (q--){
	        scanf("%d%d", &x, &y);
			printf("%d\n", lca(x,y));
		}
	}
	return 0;
}

