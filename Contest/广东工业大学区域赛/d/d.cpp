#include <cstdio>
#include <iostream>
using namespace std;
int a[200];
int main(){
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int ans=0;
		for (int i=1;i<=n;i++){
			if (a[i]==0) ans++;
			if (a[i]==3&&i>1){
				if (a[i-1]==1) a[i]=2;
				if (a[i-1]==2) a[i]=1;
			}
			if (a[i]==3&&i==1){
				if (a[i+1]==1) a[i]=2;
				if (a[i+1]==2) a[i]=1;
			}
			if (a[i]==a[i-1]&&a[i]!=0&&a[i]!=3){
				a[i]=0;
				ans++;
			}
		}
		printf("%d\n",-24*ans);
	}
}
