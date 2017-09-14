#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int ep,c;
	node(int _ep,int _c):ep(_ep),c(_c){}
};

vector<node> edge[1111];
int dist[1111];
int ans[1111];

struct cmp{
	bool operator ()(const int &x,const int &y){
		return dist[x]>dist[y];
	}
};

priority_queue<int,vector<int>,cmp> Q;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	int n,t,v,c;
	while(~scanf("%d",&n),n){
		memset(ans,0,sizeof(ans));
		for(int i=0;i<1111;i++) edge[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			for(int cnt=1;cnt<=t;cnt++){
				scanf("%d%d",&v,&c);
				edge[i].push_back(node(v,c));
			}
		}
		for(int s=1;s<=n;s++){
			memset(dist,63,sizeof(dist));
			while(!Q.empty()) Q.pop();
			dist[s]=0;
			Q.push(s);
			while(!Q.empty()){
				int now = Q.top();Q.pop();
				for(int i=0;i<edge[now].size();i++){
					if(dist[now]+edge[now][i].c<dist[edge[now][i].ep]){
						dist[edge[now][i].ep]=dist[now]+edge[now][i].c;
						Q.push(edge[now][i].ep);
					}
				}
			}
			int mx=0;
			int flag=1;
			for(int i=1;i<=n;i++)
				if(mx<dist[i]&&i!=s&&dist[i]!=dist[0]) mx=dist[i];
			for(int i=1;i<=n;i++)
				if(dist[i]==dist[0]){
					flag=0;
					break;
				}
			ans[s]=mx;
			if(!flag) ans[s]=dist[0];
		}
		int ansi,mn=dist[0],flag=1;
		for(int i=1;i<=n;i++)
			if(mn>ans[i]){
				if(ans[i]==dist[0]){
					flag=0;
					break;
				}
				mn=ans[i];
				ansi=i;
			}
		if(flag) printf("%d %d\n",ansi,mn);
		else puts("disjoint");
	}
	return 0;
} 
