#include <stdio.h>
#include <string.h>
int main()
{
	int m,i;
	scanf("%d",&m);
	while (m--) 
	{
		char s[11111];
		int n = 0;
		scanf("%s",&s);
		for (i = 0; i < strlen(s); i++) 
		{
			if (s[i] >= '0' && s[i] <= '9')
				n++;
		}
		printf("%d\n",n);
	}
	return 0;
}
