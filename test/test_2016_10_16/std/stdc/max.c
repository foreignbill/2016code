#include <stdio.h>

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n,i,max,a;
	scanf("%d",&n);
	scanf("%d",&max);
	for(i=2;i<=n;i++){
		scanf("%d",&a);
		if(a>max) max=a;
	}
	printf("%d\n",max);
	return 0;
} 
