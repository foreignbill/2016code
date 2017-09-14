#include <bits/stdc++.h>
using namespace std;
int g[11][11];
int v[13][13];
int v2[13][13]; 
int range[13][13];
const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,-1,1};
int n,m,s=0,mn=INT_MAX;
int find(int x, int y, int id){
	if(v2[x][y]) return 0;
    int tot=0;
    if(range[x][y]==0) return 0;
    if(v[x][y]!=id) return 0;
    if(v[x][y]==id) tot++;
    v2[x][y]=1;
	for(int i=1;i<=4;i++){
		tot += find(x+dx[i],y+dy[i],id);
	}
    return tot;
}

bool checkb(int x,int y){
	memset(v2,0,sizeof(v2));
	int f1=find(x,y,1);
	int f2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(v[i][j]==1) continue;
			memset(v2,0,sizeof(v2));
			f2=find(i,j,0);
			return f1+f2==m*n;
		}
}

bool check(int i,int j){
	if(!range[i][j]) return 0;
	v[i][j]=1;
	bool pan=checkb(i,j);
	v[i][j]=0;
	return pan;
}

int dfs(int i,int j,int dep,int s){
	if(s<g[i][j]) return 0;
	if(v[i][j]) return 0;
	if(check(i,j)==0) return 0;
	if(s==g[i][j]){
		if(dep<mn) mn=dep;
		return 0;
	}
	v[i][j]=1;
	for(int cnt=1;cnt<=4;cnt++){
		dfs(i+dx[cnt],j+dy[cnt],dep+1,s-g[i][j]);
	}
	v[i][j]=0;
}

int main(){
	scanf("%d%d",&m,&n);
	memset(v,0,sizeof(v));
	memset(range,0,sizeof(range));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
			s+=g[i][j];
			range[i][j]=1;
		}
	if(s%2==1){
		puts("0");
		return 0;
	}
	s/=2;
	dfs(1,1,0,s);
	printf("%d\n",mn+1);
	return 0;
}
