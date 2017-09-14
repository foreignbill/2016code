#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2005
#define M 250000
#define inf 0x3f3f3f3f
using namespace std;
struct YYC
{
	int u,v,len,cost,next;
}e[M],road[M>>1];
int head[N],cnt;
inline void add(int u,int v,int len)
{
	e[++cnt].v=v;
	e[cnt].len=len;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dist[N];
bool in[N];
queue<int>q;
void spfa(int s)
{
	while(!q.empty())q.pop();
	memset(dist,0x3f,sizeof(dist));
	memset(in,0,sizeof(in));
	int i,u,v;
	q.push(s),dist[s]=0,in[s]=1;
	while(!q.empty())
	{
		u=q.front(),q.pop(),in[u]=0;
		for(i=head[u];i;i=e[i].next)
		{
			v=e[i].v;
			if(dist[v]>dist[u]+e[i].len)
			{
				dist[v]=dist[u]+e[i].len;
				if(!in[v])q.push(v),in[v]=1;
			}
		}
	}
	return ;
}
int s,t,d[N];
bool bfs()
{
	memset(d,0,sizeof(d));
	while(!q.empty())q.pop();
	int i,u,v;
	q.push(s);
	d[s]=1;
	while(!q.empty())
	{
		u=q.front(),q.pop();
		for(i=head[u];i;i=e[i].next)
		{
			v=e[i].v;
			if(!d[v]&&e[i].len)
			{
				d[v]=d[u]+1;
				if(v==t)return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
int dinic(int x,int flow)
{
	if(x==t)return flow;
	int i,v,remain=flow,k;
	for(i=head[x];i&&remain;i=e[i].next)
	{
		if(d[v=e[i].v]==d[x]+1&&e[i].len)
		{
			k=dinic(v,min(remain,e[i].len));
			if(!k)d[v]=0;
			e[i].len-=k,e[i^1].len+=k;
			remain-=k;
		}
	}
	return flow-remain;
}
int n,m,T;
int main(){
	freopen("d.in","r",stdin); 
	int i,j,k;
	int a,b,c,d;
    while(scanf("%d",&T)!=EOF){
		while(T--){
			while(!q.empty())q.pop();
			scanf("%d%d",&n,&m);
			memset(head,0,sizeof(head));
			cnt=0;
			for(i=1;i<=m;i++)
			{
				scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].cost);
				road[i].len=1;
				add(road[i].u,road[i].v,road[i].len);
				add(road[i].v,road[i].u,road[i].len);
			}
			spfa(1);
			cnt=1;
			memset(head,0,sizeof(head));
			for(i=1;i<=m;i++){
				if(dist[road[i].u]+road[i].len==dist[road[i].v])add(road[i].u,road[i].v,road[i].cost),add(road[i].v,road[i].u,0);
				if(dist[road[i].v]+road[i].len==dist[road[i].u])add(road[i].v,road[i].u,road[i].cost),add(road[i].u,road[i].v,0);
			}
			
			s=1,t=n;
			
			
			int maxflow=0;
			while(bfs())maxflow+=dinic(s,inf);
			printf("%d\n",maxflow);
		}
	}
	return 0;
}
