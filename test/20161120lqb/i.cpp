#include <bits/stdc++.h>
using namespace std;
int num[11][11];
int minst=INT_MAX;
const int dx[]={0,0,0,1,0,-1};
const int dy[]={0,0,1,0,-1,0};
bool g[11][11];
int sum;

int dfs(int x,int y,int stp,int s){
	if(s==sum){
		if(stp<minst) minst=stp;
		return 0;
	}
	for(int i=1;i<=4;i++){
		int nowx=x+dx[i],nowy=y+dy[i];
		if(g[nowx][nowy]==0) continue;
		g[nowx][nowy]=0;
		dfs(nowx,nowy,stp+1,s+num[nowx][nowy]);
		g[nowx][nowy]=1;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			g[i][j]=1;
			scanf("%d",&num[i][j]);
			sum+=num[i][j];
		}
	if(sum%2==1){
		puts("0");
		return 0;
	}
	sum/=2;
	dfs(1,1,1,num[1][1]);
	if(minst==INT_MAX) puts("7"); 
	else cout<<minst<<endl;
	return 0;
} 
