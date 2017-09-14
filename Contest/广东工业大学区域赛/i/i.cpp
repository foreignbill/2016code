#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

struct node{
	int x,y;
}g[1111][1111];

bool f[1111][1111];

int main(){
	freopen("input.txt","r",stdin);
	int T,n,m;
	scanf("%d\n",&T);
	for(int cnt=1;cnt<=T;cnt++){
		scanf("%d %d\n",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)scanf("(%d,%d)",&g[i][j].x,&g[i][j].y);
			getchar();
		}
		memset(f,0,sizeof f);
		f[1][1]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==1&&j==1) continue;
				if(g[i][j].x==2&&g[i][j].y==4){ //2 4
					f[i][j]=0;
					continue;
				}
				if(g[i][j].x==2&&g[i][j].y==5){//2 5
					f[i][j]=0;
					continue;
				}
				
				if(g[i][j].x==2&&g[i][j].y==0&&
				((g[i][j-1].x==2&&g[i][j-1].y==3)
				||(g[i][j-1].x==3&&g[i][j-1].y==0)
				||(g[i][j-1].x==3&&g[i][j-1].y==2)
				||(g[i][j-1].x==3&&g[i][j-1].y==3)
				||(g[i][j-1].x==4&&g[i][j-1].y==0))) f[i][j]=f[i][j-1]; //(2,0)
				
				if(g[i][j].x==2&&g[i][j].y==1&&
				((g[i-1][j].x==2&&g[i-1][j].y==2)
				||(g[i-1][j].x==3&&g[i-1][j].y==0)
				||(g[i-1][j].x==2&&g[i-1][j].y==1)
				||(g[i-1][j].x==3&&g[i-1][j].y==1)
				||(g[i-1][j].x==4&&g[i-1][j].y==0)
				||(g[i-1][j].x==3&&g[i-1][j].y==3))) f[i][j]=f[i-1][j]; //(2,1)
				
				if(g[i][j].x==2&&g[i][j].y==2&&
				((g[i][j-1].x==2&&g[i][j-1].y==3)
				||(g[i][j-1].x==3&&g[i][j-1].y==0)
				||(g[i][j-1].x==3&&g[i][j-1].y==2)
				||(g[i][j-1].x==3&&g[i][j-1].y==3)
				||(g[i][j-1].x==4&&g[i][j-1].y==0))) f[i][j]=f[i][j-1]; //(2,2)
				
				if(g[i][j].x==2&&g[i][j].y==3&&
				((g[i-1][j].x==2&&g[i-1][j].y==2)
				||(g[i-1][j].x==3&&g[i-1][j].y==0)
				||(g[i-1][j].x==2&&g[i-1][j].y==1)
				||(g[i-1][j].x==3&&g[i-1][j].y==1)
				||(g[i-1][j].x==4&&g[i-1][j].y==0)
				||(g[i-1][j].x==3&&g[i-1][j].y==3))) f[i][j]=f[i-1][j]; //(2,3)

				if(g[i][j].x==3&&g[i][j].y==0&&
				((g[i][j-1].x==2&&g[i][j-1].y==3)
				||(g[i][j-1].x==3&&g[i][j-1].y==0)
				||(g[i][j-1].x==3&&g[i][j-1].y==2)
				||(g[i][j-1].x==3&&g[i][j-1].y==3)
				||(g[i][j-1].x==4&&g[i][j-1].y==0))) f[i][j]=f[i][j-1]; //(3,0)
						
				if(g[i][j].x==3&&g[i][j].y==3&&
				((g[i-1][j].x==2&&g[i-1][j].y==2)
				||(g[i-1][j].x==3&&g[i-1][j].y==0)
				||(g[i-1][j].x==2&&g[i-1][j].y==1)
				||(g[i-1][j].x==3&&g[i-1][j].y==1)
				||(g[i-1][j].x==4&&g[i-1][j].y==0)
				||(g[i-1][j].x==3&&g[i-1][j].y==3))) f[i][j]=f[i-1][j]; //(3,3)
				
				if(g[i][j].x==3&&g[i][j].y==1){
					if((g[i-1][j].x==2&&g[i-1][j].y==2)
					||(g[i-1][j].x==3&&g[i-1][j].y==0)
					||(g[i-1][j].x==2&&g[i-1][j].y==1)
					||(g[i-1][j].x==3&&g[i-1][j].y==1)
					||(g[i-1][j].x==4&&g[i-1][j].y==0)
					||(g[i-1][j].x==3&&g[i-1][j].y==3)) f[i][j]=f[i-1][j];
					if(f[i][j]) continue;
					if((g[i][j-1].x==2&&g[i][j-1].y==3)
					||(g[i][j-1].x==3&&g[i][j-1].y==0)
					||(g[i][j-1].x==3&&g[i][j-1].y==2)
					||(g[i][j-1].x==3&&g[i][j-1].y==3)
					||(g[i][j-1].x==4&&g[i][j-1].y==0)) f[i][j]=f[i][j-1]; 
				}
				if(g[i][j].x==3&&g[i][j].y==2){
					if((g[i-1][j].x==2&&g[i-1][j].y==2)
					||(g[i-1][j].x==3&&g[i-1][j].y==0)
					||(g[i-1][j].x==2&&g[i-1][j].y==1)
					||(g[i-1][j].x==3&&g[i-1][j].y==1)
					||(g[i-1][j].x==4&&g[i-1][j].y==0)
					||(g[i-1][j].x==3&&g[i-1][j].y==3)) f[i][j]=f[i-1][j];
					if(f[i][j]) continue;
					if((g[i][j-1].x==2&&g[i][j-1].y==3)
					||(g[i][j-1].x==3&&g[i][j-1].y==0)
					||(g[i][j-1].x==3&&g[i][j-1].y==2)
					||(g[i][j-1].x==3&&g[i][j-1].y==3)
					||(g[i][j-1].x==4&&g[i][j-1].y==0)) f[i][j]=f[i][j-1]; 
				}
				if(g[i][j].x==4&&g[i][j].y==0){
					if((g[i-1][j].x==2&&g[i-1][j].y==2)
					||(g[i-1][j].x==3&&g[i-1][j].y==0)
					||(g[i-1][j].x==2&&g[i-1][j].y==1)
					||(g[i-1][j].x==3&&g[i-1][j].y==1)
					||(g[i-1][j].x==4&&g[i-1][j].y==0)
					||(g[i-1][j].x==3&&g[i-1][j].y==3)) f[i][j]=f[i-1][j];
					if(f[i][j]) continue;
					if((g[i][j-1].x==2&&g[i][j-1].y==3)
					||(g[i][j-1].x==3&&g[i][j-1].y==0)
					||(g[i][j-1].x==3&&g[i][j-1].y==2)
					||(g[i][j-1].x==3&&g[i][j-1].y==3)
					||(g[i][j-1].x==4&&g[i][j-1].y==0)) f[i][j]=f[i][j-1];
				}
			}
		if(f[n][m]){
			printf("Case %d:\n",cnt);
			puts("Well done!");
		}
		else{
			printf("Case %d:\n",cnt);
			puts("What a pity!");
		}
	}
	
	return 0;
} 
