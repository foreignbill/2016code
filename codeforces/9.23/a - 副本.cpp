#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,t;
	scanf("%d",&n);
	if(n==1){
		scanf("%d",&t);
		if(t==0) puts("UP");
		if(t==15) puts("DOWN");
		if(t!=0&&t!=15) puts("-1");
	}
	else{
		for(int i=1;i<=n-2;i++) scanf("%d",&t);
		scanf("%d%d",&a,&b);
		string ans="";
		if(b>a){
			if(b==15) ans="DOWN";
			else      ans="UP";
		}
		if(b<a){
			if(b==0) ans="UP";
			else	 ans="DOWN";
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
