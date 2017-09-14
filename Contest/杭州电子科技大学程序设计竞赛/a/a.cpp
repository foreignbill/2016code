#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int T;char st[1111];
	scanf("%d",&T);
	getchar();
	while(T--){
		gets(st);
		int len=strlen(st);
		if(st[len-1]=='?'){
			puts("-_-");
			continue;
		}
		if(st[len-1]=='.'){
			puts("Orz");
			continue;
		}
		if(st[len-1]=='!'){
			int cnt=0;
			for(int i=len-1;i;i--){
				if(st[i]=='!') cnt++;
			}
			putchar('W');
			for(int i=1;i<=cnt;i++) putchar('o');
			puts("w!");
		}
	}
	
	return 0;
} 
