#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	while(cin>>T){
		while(T--){
			int a,b;
			scanf("%d%d",&a,&b);
				printf("%d\n",max(a,b)*2+min(a,b));
		}
	}
	
	return 0;
}
