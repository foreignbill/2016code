#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		int tmp,count=0;
		tmp=n/5;
		
		while(tmp){
			count+=tmp;
			tmp/=5;
		}
		
		printf("%d\n",count);
	}
	return 0;
} 
