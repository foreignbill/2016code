#include <stdio.h>
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	char ch;
	int n,i;
	scanf("%d\n",&n); 
	for(i=1;i<=n;i++){
		scanf("%c",&ch);
		if('A'<=ch&&ch<='Z') putchar(ch+32);
		else putchar(ch);
	}
	printf("\n");
	return 0;
} 
