#include  <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
const int INF=0x7f7f7f;
const int N=2e5+10000;
struct edge
{
    int next,v,w;
} edge[N];
int cnt,head[N];
long long dis[N];
void init()
{
    memset(head,-1,sizeof(head));
    memset(dis,INF,sizeof(dis));
    cnt=0;
}
void add(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void bfs(int st,int ed)
{
    queue<int>q;
    q.push(st);
    set<int>fa,fb;
    int i;
    dis[st]=0;
    for(i=1; i<=ed; i++)
    {
        if(i!=st)
            fa.insert(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(i=head[u]; ~i; i=edge[i].next)
        {
            int v=edge[i].v;
            if(!fa.count(v))
                continue;
            fa.erase(v);
            fb.insert(v);
        }
        for(set<int>:: iterator it=fa.begin(); it!=fa.end(); it++)
        {
            q.push(*it);
            dis[*it]=dis[u]+1;
        }
        fa.swap(fb);
        fb.clear();
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,s;
        cin>>n>>m;
        init();
        for(int i=1; i<=m; i++)
        {
            int u,v;
            cin>>u>>v;
            add(u,v,1);
            add(v,u,1);
        }
        cin>>s;
        bfs(s,n);
        int ok=0;
        for(int i=1; i<=n; i++)
        {
            if(i==s)
                continue;
            if(ok)
                cout<<" ";
            ok=1;
            if(dis[i]==INF)
                cout<<-1;
            else
                cout<<dis[i];
        }
        cout<<endl;
    }
    return 0;
}
