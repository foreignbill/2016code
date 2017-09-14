#include <stdio.h>

int main(){
	freopen("sigma.in","r",stdin);
	freopen("sigma.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",(a+b)*(b-a+1)/2); 
	return 0;
} 
