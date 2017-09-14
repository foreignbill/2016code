#include <cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long a,b;
		scanf("%llo%llo",&a,&b);
		printf("%llo\n",a-b);
	}
	return 0;
}
