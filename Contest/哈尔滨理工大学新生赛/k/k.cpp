#include <cstdio>
#include <cstring>
using namespace std;
char st[10086];
int main(){
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d\n",&T);
	while(T--){
		gets(st);
		int tp = 0;
		int len=strlen(st);
		while(tp<len){
			int i = tp+1;
			if(!('0'<=st[i]&&st[i]<='9') ){
				putchar(st[tp]);
				tp=i;
				continue;
			}
			if('0'<=st[i]<='9'){
				int x=st[i]-'0';
				while('0'<=st[i+1]&&st[i+1]<='9'){
					x = x + st[i+1]-'0';
					i++;
				}
				for(int cnt=0;cnt<=x;cnt++) putchar(st[tp]);
				tp = i + 1;
			}
		}
		puts("");
	} 
	
	return 0;
}
