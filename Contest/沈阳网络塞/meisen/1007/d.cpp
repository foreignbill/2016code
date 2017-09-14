#include <cstdio>

using namespace std;

int dfs(int id){
	
	
}

int main(){
	
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(base,0,sizeof(base));
		int top=0,t=i;
		while(t){
			top++;
			base[top]=t%10;
			t/=10;
		}
		if(dfs(1)) ans++;
	}
	
	return 0;
} 
