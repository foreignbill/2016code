#include <bits/stdc++.h>
using namespace std;

int n,m,cost[111],value[111],e[11111],head[5555],next[11111],f[111][111];
bool v[111];

int dfs(int id){
	
}

int main(){
	while(scanf("%d%d",&n,&m),n!=-1&&m!=-1){
		for(int i=1;i<=n;i++) scanf("%d%d",cost+i,value+i);
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&x,&y);
			e[i]=y;
			next[i]=head[x];
			head[x]=i;
			
			e[i+m]=x;
			next[i+m]=head[y];
			head[y]=i+m; 
		}
		memset(f,0,sizeof f);
		memset(v,0,sizeof v); 
		dfs(1);
		printf("%d\n",f[1][m]);
	}
	
	return 0;
} 
