#include <bits/stdc++.h>
using namespace std;
int T,n,m,s,u,v,ans;
vector<int> e[1111];
int g[111][111];
int data[110];
int dfs(int id,int size){
	if(size==s){
		ans++;
		return 0;
	}
	for(int i=0;i<e[id].size();i++){
		int ep=e[id][i];
		bool flag=true;
		for(int j=1;j<=size;j++){
			if(!g[ep][data[j]]){
				flag=false;
				break;
			}
		}
		if(flag){
			size++;
			data[size]=ep;
			dfs(ep,size);
			data[size]=0;
			size--;
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset(g,0,sizeof(g));
		scanf("%d%d%d",&n,&m,&s);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			if(u>v) swap(u,v);
			e[u].push_back(v);
			g[u][v]=g[v][u]=1;
		}
		ans=0;
		for(int i=1; i<=n; i++){
            int size=1;
            data[1]=i;
            dfs(i,1);
        }
		printf("%d\n",ans);
	}
	return 0;
}
