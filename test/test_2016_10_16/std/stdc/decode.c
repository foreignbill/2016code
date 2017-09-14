#include <stdio.h>

int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	char ch;
	int n,i;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		scanf("%c",&ch);
		if(ch=='f') putchar('t');
		else putchar(ch);
	}
	printf("\n");
	return 0;
} 
