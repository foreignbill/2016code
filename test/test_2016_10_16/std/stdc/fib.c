#include <stdio.h>

int main(){
	freopen("fib.in","r",stdin);
	freopen("fib.out","w",stdout);
	int n;
	scanf("%d",&n);
	int f[100],i;
	f[1]=1,f[2]=1;
	for(i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	printf("%d\n",f[n]);
	return 0;
} 
