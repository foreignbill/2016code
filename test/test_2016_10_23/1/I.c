#include <stdio.h>

int isprime(int x){
	int i;
	for(i=2;i*i<=x;i++)
		if(x%i==0) return 0; 
		
	return 1;
}

int main(){
	int n,i;
	while(scanf("%d",&n),n){
		int ans=0;
		for(i=2;i+i<n;i++)
			if(isprime(i)&&isprime(n-i)) ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
