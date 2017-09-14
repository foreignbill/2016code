#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("d.in","w",stdout);
	srand((unsigned)time(0));
	int t=10;
	while(t--){
		int n=rand() % 2000 + 1;
		while(n==0) n=rand() % 2000 + 1;
		printf("%d ",n);
		int b=rand() % n + 1; 
		int a=rand() % (b-1) + 1;
		printf("%d %d\n",a,b);
		for(int i=1;i<=n;i++){
			int x=rand() % 20 + 1;
			printf("%d ",x);
		}
		puts("");
	}
	puts("0");
	return 0;
}
