#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int getmax(int n){
	int bit[10]={0},top=0;
	while(n){
		bit[++top]=n%10;
		n/=10;
	}
	sort(bit+1,bit+1+top);
	int x=0;
	for(int i=top;i>=1;i--) x = x*10 + bit[i];
	return x;
}

int getmin(int n){
	int bit[10]={0},top=0;
	while(n){
		bit[++top]=n%10;
		n/=10;
	}
	sort(bit+1,bit+1+top);
	int x=0;
	for(int i=1;i<=top;i++) x = x*10 + bit[i];
	return x;
}

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		int ans=0,x=n;
		while(1){
			ans++;
			int t1=getmax(x);
			int t2=getmin(x);
			x=t1-t2;
			if(x==6174) break;
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
