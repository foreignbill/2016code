#include <bits/stdc++.h>

using namespace std;

const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,-1,1};

int n,m,g[55][55];

bool check(){
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(g[i][1]==g[j][1]) return 1;
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(g[i][m]==g[j][m]) return 1;
	for(int i=1;i<=m-1;i++)
		for(int j=i+1;j<=m;j++)
			if(g[1][i]==g[1][j]) return 1;
	for(int i=1;i<=m-1;i++)
		for(int j=i+1;j<=m;j++)
			if(g[n][i]==g[n][j]) return 1;
	for(int i=2;i<=n-1;i++)
		for(int j=2;j<=m-1;j++)
			for(int k=1;k<=4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(g[i][j]==g[nx][ny]) return 1;
			}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	int id=1;
	while(T--){
		scanf("%d%d",&n,&m);
		memset(g,-1,sizeof(g));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&g[i][j]);
		if(check()) printf("Case #%d: Yes\n",id++);
		else        printf("Case #%d: No\n",id++);
	}
	
	return 0;
} 
