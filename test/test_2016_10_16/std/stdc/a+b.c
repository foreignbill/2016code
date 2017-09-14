#include <stdio.h>

int main(){
	freopen("a+b.in","r",stdin);
	freopen("a+b.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",a+b);
	return 0;
}

