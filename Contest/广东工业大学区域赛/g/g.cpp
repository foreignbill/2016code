#include <cstdio>
#include <cstring>

#define LL long long 

LL f[100][100];

int main(){
	f[0][0]=1;
	f[1][0]=1;f[1][1]=1;
	for(int i=2;i<=11;i++)
		for(int j=0;j<=i;j++)  f[i][j]=f[i-1][j-1]+f[i-1][j];
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		printf("%lld\n",f[n][k]);
	}
	
	return 0;
} 
