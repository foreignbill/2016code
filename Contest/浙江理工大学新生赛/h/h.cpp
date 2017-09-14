#include <bits/stdc++.h>
#define LL long long 
using namespace std;
LL read(){  
    LL x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}
LL f[99];
bool dfs(LL n,LL m){
	if(n==2) return m==1;
	if(n==1) return 1;
	if(m> f[n-1]) dfs(n-2,m-f[n-1]);
	else dfs(n-1,m);
}
int main(){
	LL T,n,m;
	cin>>T;
	f[0]=1;f[1]=1;
	for(int i=2;i<=91;i++) f[i]=f[i-1]+f[i-2];
	while(T--){
		n=read();m=read();
		puts(dfs(n,m)?"a":"b");
	}
	return 0;
}
