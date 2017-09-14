#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","w",stdout);
	srand((unsigned)time(0));
	puts("2");
	printf("%d %d %d %d %d\n",-rand()*10 % 100000,-rand()*10 % 100000,rand()*10 % 100000,rand()*10 % 100000,rand()*10 % 100000);
	printf("%d %d %d %d %d\n",rand(),rand(),-rand(),-rand(),rand());
	return 0;
} 
