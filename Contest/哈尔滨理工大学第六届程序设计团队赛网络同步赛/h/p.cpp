#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
bool v[200];
int stack[200];
int ans;

int check(int stack[],int n){
	for(int i=2;i<=n;i++)
		if(stack[i-1]+1==stack[i]) return 0;
	return 1;
}

int dfs(int id,int n){
	if(id==0){
		if(check(stack,n)){
			ans++;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!v[i]){
			v[i]=1;
			stack[++stack[0]]=i;
			dfs(id-1,n);
			v[i]=0;
			stack[0]--;
		}
}

int main(){
	
	for(int i=1;i<=10;i++){
		memset(v,0,sizeof(v));
		ans=0;
		dfs(i,i);
		cout<<ans<<endl; 
	}
	return 0;
} 
