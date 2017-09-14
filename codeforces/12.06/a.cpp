#include <cstdio>
#include <cstring>
const int d[]={6,8,4,2}; 
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0)printf("1\n");
		else{
			printf("%d\n",d[n%4]);
		}
	}
	return 0;
}
