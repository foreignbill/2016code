#include <cstdio>
#define LL long long 

using namespace std;

int main(){
	LL a,b,T,tt;
	while(scanf("%I64d",&T)!=EOF){
		int id=1;
		while(T--){
			scanf("%I64d%I64d",&a,&b);
			if(a==b) printf("Case #%d:\n",id),puts("1"),printf("%I64d %I64d\n",a,b); 
			if(a<b)  printf("Case #%d:\n",id),puts("2"),printf("%I64d %I64d\n%I64d %I64d\n",a,b,b,a);
			if(a>b)  printf("Case #%d:\n",id),puts("2"),printf("%I64d %I64d\n%I64d %I64d\n",b,a,a,b);
			id++; 
		}
	}
	
	return 0;
}
