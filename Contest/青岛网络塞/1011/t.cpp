#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 250000
#define maxn 600
#define pb push_back
#define inf 0x7fffffff/3
#define rep(i,j,k) for(int i=j;i<=k;i++)

using namespace std;

int n;

struct dinic
{
	int to[2*MAX],flow[2*MAX],next[2*MAX],head[MAX];
	int num;

 	dinic()
	{
		num=1;
	}

	void add_edge(int From,int To,int Cap)
	{
		num++;
		to[num]=To;
		flow[num]=Cap;
		next[num]=head[From];
		head[From]=num;
		num++;
		to[num]=From;
		flow[num]=0;
		next[num]=head[To];
		head[To]=num;
	}

	int s,t,done[maxn],cur[maxn],d[maxn];

	bool bfs()
	{
		memset(d,0,sizeof(d));
		memset(done,0,sizeof(done));
		queue<int>q;
		q.push(s);
		d[s]=1;
		done[s]=1;//!!!!!!!!!!!!!!!!!!!!!!
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=head[now];i;i=next[i])
			{
				if(!done[to[i]]&&flow[i])
				{
					d[to[i]]=d[now]+1;
					q.push(to[i]);
					done[to[i]]=1;
				}
			}
		}
		return done[t];
	}

	int dfs(int x,int a)
	{
		if(t==x||!a)
			return a;
		int Flow=0;
		for(int w=head[x],f;w;w=next[w])
		{
			if(d[to[w]]==d[x]+1&&(f=dfs(to[w],min(a,flow[w])))>0)
			{
				Flow+=f;
				flow[w]-=f;
				flow[w^1]+=f;
				a-=f;
				if(!a)
					break;
			}
		}
		return Flow;
	}

	int maxflow(int S,int T)
	{
		this->s=S;
		this->t=T;
		int answer=0;
		while(bfs())
		{
			answer+=dfs(s,inf);
		}
		return answer;
	}
}wbysr;

int to[2*MAX],from[2*MAX],cost[2*MAX],value[2*MAX],dis[maxn],done[maxn],head[MAX*2],next[2*MAX];
int m,tot=0;

void add(int from,int To,int Cost,int Value)
{
	to[++tot]=To;
	cost[tot]=Cost;
	value[tot]=Value;
	next[tot]=head[from];
	head[from]=tot;
}

inline void spfa()
{
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
//	memset(done,0,sizeof(done));
	dis[1]=0;
	done[1]=1;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		done[now]=0;
		for(int i=head[now];i;i=next[i])
			if(dis[to[i]]>dis[now]+cost[i])
			{
				dis[to[i]]=dis[now]+cost[i];
				if(!done[to[i]])
					done[to[i]]=1,q.push(to[i]);
			}
	}
	return;
}

int main()
{   
	freopen("d.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){ 
	scanf("%d%d",&n,&m);
	for(int i=1,a1,a2,a3=1,a4;i<=m;i++)
		scanf("%d%d%d",&a1,&a2,&a4),add(a1,a2,a3,a4),add(a2,a1,a3,a4);
	spfa();
	//make
	queue<int>q;
	q.push(n);
	memset(done,0,sizeof(done));
	done[n]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=next[i])
			if(dis[to[i]]+cost[i]==dis[now])
			{
				wbysr.add_edge(to[i],now,value[i]);
				if(!done[to[i]])
					done[to[i]]=1,q.push(to[i]);
			}
	}

	printf("%d\n",wbysr.maxflow(1,n));
}
	return 0;
}
