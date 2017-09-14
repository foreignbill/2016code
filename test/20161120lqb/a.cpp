#include <bits/stdc++.h>
using namespace std;
int main(){
	int tp,top[1111];
	char st[1111];
	scanf("%d %s",&tp,st);
	if(tp==1){
		for(int i=0;i<strlen(st);i++){
			if('a'<=st[i]&&st[i]<='z') putchar(st[i]-32);
			else putchar(st[i]);
		}
		puts("");
	}
	if(tp==2){
		for(int i=0;i<strlen(st);i++){
			if('A'<=st[i]&&st[i]<='Z') putchar(st[i]+32);
			else putchar(st[i]);
		}
		puts("");
	}
	if(tp==3){
		for(int i=strlen(st)-1;i>=0;i--) putchar(st[i]);
		puts("");
	}
	if(tp==4){
		for(int i=0;i<strlen(st);i++){
			if('A'<=st[i]&&st[i]<='Z') putchar(st[i]+32);
			if('a'<=st[i]&&st[i]<='z') putchar(st[i]-32);
		}
		puts("");
	}
	if(tp==5){
		for(int i=0;i<strlen(st);i++)if('A'<=st[i]&&st[i]<='Z') st[i]+=32;
		int s=0;
		while(s<strlen(st)){
			int i;
			for(i=s+1;i<strlen(st);i++)
				if(st[i]!=st[i-1]+1) break;
			i--;
			if(i==s||i==s+1){
				putchar(st[s]);
				s++;
				continue;
			}
			else{
				putchar(st[s]);
				putchar('-');
				putchar(st[i]);
				s=i+1;
			}
		}
	}
	return 0; 
} 
