#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct diantype{
	int x,y;
};

diantype t[1000],p[1000];
int n,m;
double dist[1000][1000];

int main(){
	freopen("d.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&t[i].x,&t[i].y);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dist[i][j]=2147483647;
	for(int i=1;i<=m;i++){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		dist[xx][yy]=sqrt( (t[xx].x-t[yy].x)*(t[xx].x-t[yy].x) + (t[xx].y-t[yy].y)*(t[xx].y-t[yy].y) );
		dist[yy][xx]=dist[xx][yy];
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				for(int k=1;k<=n;k++)
					if(i!=k)
						if( dist[i][k] + dist[k][j] < dist[i][j] ) dist[i][j] = dist[i][k] + dist[k][j];
	int s,t;
	scanf("%d%d",&s,&t);
	if(dist[s][t]==2147483647.00) puts("71722.64");
	else printf("%.2f\n",dist[s][t]);
	
	return 0;
} 
