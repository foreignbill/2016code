#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n,ans;
int g[10][10];

struct node{
	bool hang[10]={0},lie[10]={0},zheng[20]={0},fan[20]={0};
}white,black;
bool v[10][10]={0};

void dfs(int hang,int type){
	
	if(hang==n+1){
		ans++;
		return;
	}
	
	if(type==1)
		for(int i=1;i<=n;i++){
			if(white.hang[hang]==0&&white.lie[i]==0&&white.zheng[hang+i]==0&&white.fan[hang+n-i+1]==0&&g[hang][i]==1&&v[hang][i]==0){
				white.hang[hang]=1;
				white.lie[i]=1;
				white.zheng[hang+i]=1;
				white.fan[hang+n-i+1]=1;
				v[hang][i]=1;
				dfs(hang,0);
				white.hang[hang]=0;
				white.lie[i]=0;
				white.zheng[hang+i]=0;
				white.fan[hang+n-i+1]=0;
				v[hang][i]=0;
			}
		}
	if(type==0)
		for(int i=1;i<=n;i++){
			if(black.hang[hang]==0&&black.lie[i]==0&&black.zheng[hang+i]==0&&black.fan[hang+n-i+1]==0&&g[hang][i]==1&&v[hang][i]==0){
				black.hang[hang]=1;
				black.lie[i]=1;
				black.zheng[hang+i]=1;
				black.fan[hang+n-i+1]=1;
				v[hang][i]=1;
				dfs(hang+1,1);
				black.hang[hang]=0;
				black.lie[i]=0;
				black.zheng[hang+i]=0;
				black.fan[hang+n-i+1]=0;
				v[hang][i]=0;
			}
		}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%d",&g[i][j]);
	ans=0;
	dfs(1,1);//1 col  1 white 0 black 
	printf("%d\n",ans);
	return 0;
} 
