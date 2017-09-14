#include <bits/stdc++.h>

using namespace std;

int main(){
	string st1,st2,st3,st;
	st1="string";st2=".in";
	st3="10";
	st=st1+st3+st2;
	freopen(st,"w",stdout);
	srand((unsigned)time(0));
	int a,b;
	a=rand() % 10001;
	b=rand() % 10001;
	
	printf("%d %d\n",a,b);
	
	return 0;
}
