#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define max 2222 
int k[max],d[max];
bool visit[max];
int main()
{	freopen("d.in","r",stdin);
	freopen("d2.out","w",stdout); 
	int n, a, b;
	while (cin >> n &&n != 0)
	{
		scanf("%d%d", &a, &b);
		memset(visit, 0, sizeof visit); memset(d, 0, sizeof d);
		for (int i = 1; i <= n; i++)scanf("%d", &k[i]);
		queue<int>que;
		que.push(a);
		visit[a] = 1;
		bool find = 0;
		while (!que.empty())
		{
			int fr = que.front(); que.pop();
			if (fr == b){ find = 1; break; }
			int aa = fr - k[fr];
			if (aa >= 1 && aa <= n && visit[aa] == 0 )
			{
				que.push(aa);
				visit[aa] = 1;
				d[aa] = d[fr] + 1;
			}
			aa = fr + k[fr];
			if (aa >= 1 && aa <= n&&visit[aa] == 0)
			{
				que.push(aa);
				visit[aa] = 1;
				d[aa] = d[fr] + 1;
			}
		}
		if (find)cout << d[b] << endl;
		else cout << "-1\n";
	}
}

