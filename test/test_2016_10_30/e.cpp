#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int T,n,a,b;
	cin>>T;
	for(int i=1;i<=T;i++){
		scanf("%d%d%d",&n,&a,&b);
		
		while(b){
			if(a>b) swap(a,b);
			b%=a;
		}
		
		if(n/a%2) printf("Case #%d: Yuwgna\n",i);
		else printf("Case #%d: Iaka\n",i);
	}
	return 0;
}
