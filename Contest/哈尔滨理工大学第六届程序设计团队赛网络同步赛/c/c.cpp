#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		long long n,x,ans;
		scanf("%lld",&n);
		scanf("%lld",&x);
		ans=x;
		for(int i=2;i<=n;i++){
			scanf("%lld",&x);
			ans^=x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
