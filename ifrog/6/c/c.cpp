#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		if(n%3) printf("%d\n",n); 
		else printf("%d\n",n/3);
	}
	
	return 0;
} 
