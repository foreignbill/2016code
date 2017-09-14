#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int T,n,x,tot;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			tot+=x;
		}
		printf("%.2lf\n",tot*1.0/n);
	}
	return 0;
} 
