#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char st[2048];
int n;

int print(int l,int r){
	if(l==r){
		putchar(st[l]=='1'?'I':'B');
		return st[l]=='1';
	}
	int mid = (l + r) / 2;
	int t1=print(l,mid);
	int t2=print(mid+1,r);
	if(t1==2||t2==2){
		putchar('F');
		return 2;
	}
	if(t1+t2==1){
		putchar('F');
		return 2;
	}
	if(t1==1&&t2==1){
		putchar('I');
		return 1;
	}
	if(t1==0&&t2==0){
		putchar('B');
		return 0;
	}
}

int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d\n",&n);
		gets(st+1);
		print(1,strlen(st+1));
		puts("");
	} 
	return 0;
} 
