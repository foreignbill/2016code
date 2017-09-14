#include <cstdio>
using namespace std;
int main(){
	int k;
	scanf("%d",&k);
	int n=0;
	double tt=0;
	while(1){
		n++;
		tt=tt+1.0/n;
		if(tt>=k) break;
	}
	printf("%d\n",n);
	return 0;
}

