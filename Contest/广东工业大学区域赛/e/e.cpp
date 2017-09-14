#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int num[1111111],a[1111111];

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		a[1]=1;
		int mx=0;
		scanf("%d",&num[1]);
		for(int i=2;i<=n;i++){
			scanf("%d",&num[i]);
			if(num[i]<=num[i-1]){
				a[i]=a[i-1]+1;
				if(a[i]>mx) mx=a[i];
			}
		}
		if(mx!=0){
			int ans=n/mx;
			if(n%mx) ans++;
			printf("%d\n",ans);
			if(T!=0) puts("");
		}
		else{
			printf("%d\n",n);
			if(T!=0) puts("");
		}
	}
	
	return 0;
}
