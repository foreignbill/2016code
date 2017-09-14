#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int t,n,m,x,y; 
int a[111111],du[111111];

int main(){
	freopen("d.in","r",stdin);
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof(a));
			memset(du,0,sizeof(du));
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			for(int i=1;i<=m;i++){
				scanf("%d%d",&x,&y);
				du[x]++;
				du[y]++;
			}
			
			int t=1,s=0;
			for(int i=1;i<=n;i++) if(du[i]%2) s++;
			if(s>2) t=0;
			if(s==2)t=2;
			s=0;
			for(int i=1;i<=n;i++) if(((du[i]+1)/2)%2==1) s^=a[i];
			int ans=s;
			
			if(t==1){
				ans=s^a[1];
				for(int i=2;i<=n;i++)
					ans=max(ans,s^a[i]);
			}
			
			if(t==0) puts("Impossible");
			
			if(t) printf("%d\n",ans);
		}
	}
	
	
	return 0;
} 
