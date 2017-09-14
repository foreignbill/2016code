#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		int ans = sqrt(n);
		printf("%d\n",ans);
	}
	
	return 0;
} 
