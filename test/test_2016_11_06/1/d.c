#include <stdio.h>
int isprime(int n){
	for(int i=2;i*i<=n;i++)
		if (n%i==0) return 0;
	return 1;
}
int main(){
	int x,y;
	while(scanf("%d%d",&x,&y)==2,x||y){
		int ok=1;
		for(int i=x;i<=y;i++)
			if(!isprime(i*i+i+41)){
				ok=0;
				break;
			}
		puts(ok?"OK":"Sorry");
	}
	return 0;
}

