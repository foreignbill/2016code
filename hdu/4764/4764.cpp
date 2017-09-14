#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k),n||k){
		int r=(n-1)%(k+1);
		puts(r?"Tang":"Jiang");
	}
	
	return 0;
} 
//∞Õ ≤≤©ﬁ»
