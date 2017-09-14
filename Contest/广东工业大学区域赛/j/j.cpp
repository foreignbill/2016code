#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <cmath>

using namespace std;

int prime[20001];

int isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

int main(){
	for(int i=2;i<=20001;i++)
		if(isprime(i)) prime[++prime[0]]=i;
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans;
		scanf("%d",&n);
		int mn=INT_MAX;
		for(int i=1;i<=prime[i];i++)
			if(mn>abs(prime[i]*prime[i]-n)){
				mn = abs(prime[i]*prime[i]-n);
				ans = prime[i]*prime[i];
			}
		printf("%d\n",ans); 
	}
	
	return 0;
}
