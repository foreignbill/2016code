#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,s,t,f,r;
int head[11111],e[11111],next[11111],w[11111];
int dist[11111];
bool b[11111];
int q[11111],g[11111];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,ww,k;
		scanf("%d%d%d",&x,&y,&ww);
		e[2*i-1]=y;
		next[2*i-1]=head[x];
		head[x]=2*i-1;
		w[2*i-1]=ww; 
		e[2*i]=x;
		next[2*i]=head[y];
		head[y]=2*i;
		w[2*i]=ww;
		g[i]=ww;
	}
	sort(g+1,g+m);
	memset(dist,63,sizeof(dist));
	scanf("%d%d",&s,&t);
	for(int i=1;i<=m;i++){
		min
		dist[s]=0;
		f=1;r=1;
		q[1]=s;
		memset(v,0,sizeof(v));
		v[s]=1; 
		while(f<=r){
			int now=q[f];
			for(k=head[now];k;k=next[k]){
				
			}
		} 
	}
	return 0;
}
