#include<stdio.h>
#include<string.h>
int main(){
	char ch[104];
	int i;
	while (gets(ch)!='\0'){
		int len=strlen(ch);
		if(ch[0]==' ') printf("%c",ch[0]);
		else printf("%c",ch[0]-32);
		
		for (i=1;i<len;i++)
		 if (ch[i-1]==' '&&ch[i]!=' ') printf("%c",ch[i]-32);
		  else printf("%c",ch[i]);
		
		printf("\n");
	}
	return 0;
}
