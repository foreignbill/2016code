#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("t.txt","w",stdout);
	srand((unsigned)time(0));
	int t=10;
	while(t--){
		int n=rand() % 100001;
		while(n==0) n=rand() % 100001;
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			int l,r;
			r=rand() % (n) + 1;
			l=rand() % (r) + 1;
			printf("%d %d\n",l,r);
		}
	}
	puts("0");
	return 0;
} 
