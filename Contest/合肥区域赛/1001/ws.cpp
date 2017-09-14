#include <cstdio>
#include <cstring>
#include <queue>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#define maxn 2020
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct Graph{
    int n;
    vector<int> E[maxn];
    int d[maxn];
    void init(int _n)
    {
        n = _n;
        for(int i=0 ; i<=n ; ++i)E[i].clear();
    }

    void addedge(int u,int v)
    {
        E[u].push_back(v);
    }

    bool bfs(int s)
    {
		memset(d,0,sizeof(d));
		queue<int>Q;
		Q.push(s);
		while(!Q.empty())
		{
		   int u = Q.front();Q.pop();
		   for(int i=0 ; i<E[u].size() ; ++i)
		   {
		       int v = E[u][i];
		       if(d[v])continue;
		       else {
		        d[v] = d[u]+1;Q.push(v);
		       }
		       if(d[v]>=2)return false;
		   }
		}
        return true;
    }

    bool BFS()
    {
       for(int i=1 ; i<=n ; ++i)
        if(!bfs(i))return false;
       return true;
    }
}GP,GQ;
char str[maxn];
int main()
{
    int t;cin>>t;
    int n;
    while(t--)
    {
       scanf("%d",&n);
       GP.init(n);GQ.init(n);
       for(int i=1 ; i<=n ;++i )
       {
           scanf("%s",str);
           for(int j = 0 ; j<n ; ++j)
            if(str[j]=='P')GP.addedge(i,j+1);
           else if(str[j]=='Q')GQ.addedge(i,j+1);
       }
       bool isGP = GP.BFS();
       bool isGQ = GQ.BFS();
       printf("%c\n",isGP&&isGQ?'T':'N');
    }
    return 0 ;
}

