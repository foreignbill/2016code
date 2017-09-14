#include <cstdio>
#include <iostream>
#include <cstring>

#define LL long long 

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		LL n;
		scanf("%lld",&n);
		LL ans=0;
		LL p=2;
		while(p<=n){
			ans += n/p;
			p*=2;
			//cout<<p<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
