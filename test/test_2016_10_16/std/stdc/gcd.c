#include <stdio.h>

int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	int min,i,ans=1;
	
	if(a>b) min=b;
	else    min=a;
	
	for(i=1;i<=min;i++) if(a%i==0&&b%i==0) ans=i;
	printf("%d\n",ans);
	return 0;
} 
