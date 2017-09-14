#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long

using namespace std;

LL f[2222222];
const LL base = 1000000007;

int main(){
	f[1]=1;f[2]=1;f[3]=3;
	for(LL i=4;i<=2000000;i++){
		f[i]=(i * (f[i-1]%base) % base - (i-3) * (f[i-3]%base) %base + base )%base; 
	}
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		cout<<f[n]<<endl;
	}
	return 0;
} 
