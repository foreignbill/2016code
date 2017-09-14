#include <cstdio>
#include <iostream>

using namespace std;

int ans[30000];

int base[30000];

bool isnum(int n){
	base[0]=0;
	while(n){
		base[++base[0]]=n%10;
		n/=10;
	}
	for(int i=base[0];i>=2;i--)
		if(base[i]>base[i-1]) return 0;
	return 1;
}

int main(){
	freopen("output.txt","w",stdout);
	for(int i=1;i<=100000000;i++){
		if(isnum(i)){
			ans[++ans[0]]=i;
		}
	}
	
	for(int i=1;i<=ans[0];i++) printf("%d,",ans[i]);
	
	printf("%d",ans[0]);
	return 0;
} 
