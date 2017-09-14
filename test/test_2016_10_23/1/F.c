#include<stdio.h>
#include<string.h>
char ch[100000];
int main(){
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%s",&ch);
		int len=strlen(ch);
		int ans=0;
		for (j=0;j<=len;j++)
		 if (ch[j]>='0'&&ch[j]<='9') ans++;
		 printf("%d\n",ans);
	}
	return 0;
} 
