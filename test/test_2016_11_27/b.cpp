/*#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1111111];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",a[(n+1)/2]);
	}
	return 0;
}*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1111111];
int main(){
	int n,x;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			a[x]++;
		}
		int max=0,ansi;
		for(int i=0;i<1111111;i++){
			if(a[i]<(n+1)/2) continue;
			printf("%d\n",i);
			break;
		}
	}
	
	return 0;
}
