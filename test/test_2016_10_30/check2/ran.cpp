#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("t.txt","w",stdout);
	puts("1");
	puts("10");
	srand((unsigned)time(NULL));
	for(int i=1;i<=10;i++) {
		if(i-1) printf(" "); 
		printf("%d",rand());
	}
	puts("");
	puts("1");
	int l,r;
	r=rand()%10 + 1;
	l=rand() % r + 1;
	printf("%d %d\n",l,r);
	return 0;
}
