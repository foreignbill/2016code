#include <cstdio>
#include <cstring>
#define LL long long 
using namespace std;

int main(){
	LL r,c;
	while(~scanf("%lld%lld",&r,&c)){
		LL sumrow=0,sumcol=0,row,col,x;
		scanf("%lld",&row);
		sumrow+=row;
		for(int i=2;i<=r;i++){
			scanf("%lld",&x);
			sumrow+=x;
			row = row ^ x;
		}
		scanf("%lld",&col);
		sumcol+=col;
		for(int i=2;i<=c;i++){
			scanf("%lld",&x);
			sumcol+=x;
			col = col ^ x; 
		}
		bool ok = true;
		if(sumrow!=sumcol) ok=false;
		if((row&1)^(col&1)) ok=false;
		puts(ok?"YES":"NO");
	}
	return 0;
} 
