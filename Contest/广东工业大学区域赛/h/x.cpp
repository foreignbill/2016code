#include <bits/stdc++.h> 
const int MAXS = 60*1024*1024;

int numbers[10001000];
char buf[MAXS];

void read(char *buf,int len = MAXS){
	int i;
	numbers[i=0]=0;
	for (char *p=buf;*p && p-buf<len;p++)
		if (*p == ' ')
			numbers[++i]=0;
		else
			numbers[i] = numbers[i] * 10 + *p - '0';
} 

int main(){
	freopen("input.txt","w",stdout);
	puts("10");
	for(int i=1;i<=10;i++){
		puts("1000000");
		for(int j=1;j<=1000000;j++) printf("%d ",j);
		puts("");
	}
	return 0;
} 
