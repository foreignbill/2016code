#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long  
using namespace std;
const int dx[]={1,1,2,2,-1,-1,-2,-2};
const int dy[]={2,-2,1,-1,2,-2,1,-1};
LL f[21][21];
bool g[21][21];
int main(){
	int T,n,m,x,y;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		scanf("%d%d%d%d",&n,&m,&x,&y);
		g[x][y]=1;
		for(int i=0;i<=7;i++){
			if(x+dx[i]<0||x+dx[i]>n) continue;
			if(y+dy[i]<0||y+dy[i]>m) continue;
			g[x+dx[i]][y+dy[i]]=1;
		}
		f[0][0]=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++){
				if(i==0&&j==0) continue;
				if(i==0) f[i][j]=f[i][j-1];
				if(j==0) f[i][j]=f[i-1][j];
				if(i&&j) f[i][j]=f[i-1][j]+f[i][j-1];
				if(g[i][j]) f[i][j]=0;				
			}
		cout<<f[n][m]<<endl;
	}
	return 0;
}
