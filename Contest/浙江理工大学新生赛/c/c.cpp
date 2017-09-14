#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,x;
		scanf("%d",&n);
		int mx=-1,mn=INT_MAX;
		cout<<mn<<endl;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(mx<x) mx=x;
			if(mn>x) mn=x;
		}
		printf("%d\n",mx-mn);
	}
	
	return 0;
} 
