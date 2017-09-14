#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>

#define LL long long 

using namespace std;

int main(){
	int T;
	cin>>T;
	LL n,a,b,c;
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
		int tmp = 4 - (n%4);
		if(tmp==4){
			puts("0");
			continue;
		}
		if(tmp==1){
			LL mn=INT_MAX;
			if(mn>a) mn=a;
			if(mn>(b+c)) mn=b+c;
			if(mn>(c+c+c)) mn=c+c+c;
			printf("%lld\n",mn);
		}
		if(tmp==2){
			LL mn=INT_MAX;
			if(mn>b) mn=b;
			if(mn>(a+a)) mn=a+a;
			if(mn>(c+c)) mn=c+c;
			printf("%lld\n",mn);
		}
		if(tmp==3){
			LL mn=INT_MAX;
			if(mn>c) mn=c;
			if(mn>(a+a+a)) mn=a+a+a;
			if(mn>(a+b)) mn=a+b;
			if(mn>(a+b+b+b)) mn=a+b+b+b;
			printf("%lld\n",mn);
		}
	}
	
	return 0;
}
