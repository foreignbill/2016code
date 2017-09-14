#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 2000000000

using namespace std;

const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,1,-1};
int n,m,a[101][101],l,r;
bool v[101][101];
bool pan;

bool dfs(int x,int y,int hm,int hx){
	 if(a[x][y]>hx||a[x][y]<hm) return 0;
	 if(x==1&&y==1) pan=true;
	 if(pan) return 1;
	 for(int i=1;i<=4;i++){
	 	int nowx=x+dx[i];
	 	int nowy=y+dy[i];
		if(1<=nowx&&nowx<=n&&1<=nowy&&nowy<=n)
		   if(!v[nowx][nowy]&&hm<=a[nowx][nowy]&&a[nowx][nowy]<=hx){
		   	 v[nowx][nowy]=true;
		   	 dfs(nowx,nowy,hm,hx);
		   }
	 }
}

bool check(int hm,int hx){
	memset(v,0,sizeof(v));
	pan=false;
	v[n][n]=true;
	dfs(n,n,hm,hx);
	return v[1][1];
}

int main(){
	scanf("%d",&n);
	int maxh=-INF,minh=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			maxh=max(maxh,a[i][j]);
			minh=min(minh,a[i][j]);
		}
	l=0;r=maxh-minh;
	int ans,mid;
	while(l<=r){
		mid=(l+r)>>1;
		bool pan=false;
		for(int h=minh;h<=maxh-mid;h++) if (check(h,h+mid)){
			pan=true;
			break;
		}
		if(pan){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	
	printf("%d\n",ans);
	
	return 0;
}