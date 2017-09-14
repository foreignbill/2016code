#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("d.in","w",stdout);
	srand((unsigned)time(0));
	for(int i=1;i<=10;i++) printf("%c",rand()%26+97);
	printf(" ");
	for(int i=1;i<=10;i++) printf("%c",rand()%26+97);
	printf("\n"); 
	return 0;
} 
