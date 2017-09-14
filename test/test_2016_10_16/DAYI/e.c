#include <stdio.h>
int main(){
	int n,b,i;
	while(scanf("%d",&n)!=EOF)
	{
		int r = 1;
		for (i = 0; i < n; i++) 
		{
			scanf("%d",&b);
			if (b % 2 == 1)
				r *= b;
		}
		printf("%d\n",r);
	}
	return 0;
}

