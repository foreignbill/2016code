#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int a[11111];
int f[11111];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			f[i]=INT_MAX;
			for(int j=max(0,i-m);j<i;j++)
				f[i] = min(f[i],f[j]+a[i]);
		}
		printf("%d\n",f[n]);
	}
	
	return 0;
} 
