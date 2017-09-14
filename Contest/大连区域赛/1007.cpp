#include <cstdio>
#include <cstring>

using namespace std;

long long n,m;

int main(){
	while(scanf("%I64d%I64d",&n,&m)!=EOF){
		puts((n*n/4<=m)?"T":"F");
	}
	return 0;
} 
