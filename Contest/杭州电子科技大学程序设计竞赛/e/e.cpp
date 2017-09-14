#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n,m,top;
int g[55][55];
int ans[55][55];
bool v[55][55];
bool ansflag; 

const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1}; 

struct node{
	int x,y;
}info[25555];

bool comp(node a,node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
} 

int dfs(){
	if(v[info[1].x][info[1].y]) return 0;
	
	v[info[1].x][info[1].y]=1; 
	
	for(int i=1;i<=top;i++) ans[info[i].x][info[i].y]=1;
	
	for(int i=0;i<4;i++){
		bool nostone = 1;
		for(int cnt=1;cnt<=top;cnt++){
			info[cnt].x+=dx[i];
			info[cnt].y+=dy[i];
			if(g[info[cnt].x][info[cnt].y]) nostone = 0;
			if(info[cnt].x>n||info[cnt].x<=0) nostone = 0;
			if(info[cnt].y>m||info[cnt].y<=0) nostone = 0;
		}
		if(!nostone){
			for(int cnt=1;cnt<=top;cnt++){
				info[cnt].x-=dx[i];
				info[cnt].y-=dy[i];
			}
			continue;
		}
		dfs();
		for(int cnt=1;cnt<=top;cnt++){
			info[cnt].x-=dx[i];
			info[cnt].y-=dy[i];
		}
	}
	v[info[1].x][info[1].y]=0;
}

int main(){
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);getchar();
	for(int id=1;id<=T;id++){
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&m);getchar();
		top=0;
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=m;j++){
				char ch=getchar();
				if(ch=='.') g[i][j]=0;
				if(ch=='#')	g[i][j]=1;
				if(ch=='o'){
					top++;
					info[top].x=i;
					info[top].y=j;
				}
			}
			getchar();
		}
		
		memset(ans,0,sizeof(ans));
		memset(v,0,sizeof(v));
		
		dfs();
		
		int count = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				if(g[i][j]) continue;
				count += ans[i][j];
		} 
		printf("Case #%d: %d\n",id,count);
	}
	return 0;
}
