#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char stack[10086];
char st[10086];
int main(){
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d\n",&T);
	while(T--){
		int top=0;
		char ch;
		gets(st);
		for(int i=0;i<strlen(st);i++){
			ch=st[i];
			if(ch=='#'){
				if(top) top--;
				continue;
			}
			if(ch=='@'){
				top=0;
				continue;
			}
			stack[++top]=ch;
		}
		stack[++top]='\0';
		printf("%s\n",stack+1);
	}
	return 0;
} 
