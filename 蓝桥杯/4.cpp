#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
int f[1000001];
int main(){
	f[1]=f[2]=1;
	for(int i=3;i<=1000000;i++) f[i]=(f[i-1]+f[i-2]) % MOD;
	int n;
	cin>>n;
	printf("%d\n",f[n]);			
	return 0;
} 
