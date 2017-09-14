#include <stdio.h>

int main(){
	int f[111],i,n;
	f[1]=1;
	f[2]=2;
	f[3]=3;
	f[4]=4;
	for(i=5;i<55;i++) f[i]=f[i-1]+f[i-3];
	while(scanf("%d",&n)&&n){
		printf("%d\n",f[n]);
	}

	return 0;
} 
