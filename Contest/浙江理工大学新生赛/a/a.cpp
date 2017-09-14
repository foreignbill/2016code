#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int T,n,k;
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(k!=1&&k!=n+1) puts(n%2?"BH":"LYF");
		if(k==1||k==n+1) puts("LYF");
	}
	return 0;
}
