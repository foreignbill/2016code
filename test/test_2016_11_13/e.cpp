#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int w[1234],a[1234],b[1234];
int f[2222];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof f);
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&w[i],&a[i],&b[i]);
		
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--) f[j]=max(f[j],f[j-w[i]]+a[i]+b[i]);
			
			for(int j=w[i];j<=m;j++) f[j]=max(f[j],f[j-w[i]]+a[i]); 
		}
		printf("%d\n",f[m]);
	}
	
	return 0;
} 
