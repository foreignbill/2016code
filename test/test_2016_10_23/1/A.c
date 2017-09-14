#include<string.h>
#include<stdio.h>

int main(){
	int n,k,i;
	while (scanf("%d\n",&n)!=EOF){
		for (k=1;k<=n;k++){
			int sum1=0;
			int sum2=0;
			int sum3=0;
			int sum4=0;
			int sum5=0;
			char ch[102];
			gets(ch); 
			int len=strlen(ch);
			for (i=0;i<=len;i++){
				if (ch[i]=='a') sum1++;
				if (ch[i]=='e') sum2++;
				if (ch[i]=='i') sum3++;
				if (ch[i]=='o') sum4++;
				if (ch[i]=='u') sum5++;
			}
			printf("a:%d\n",sum1);
			printf("e:%d\n",sum2);
			printf("i:%d\n",sum3);
			printf("o:%d\n",sum4);
			printf("u:%d\n",sum5);
			if (k!=n)printf("\n");
		}
	} 
	return 0;
} 
