#include <bits/stdc++.h>
using namespace std;
int w[25];
int info[11];
int n,m;
int sum[25];
inline int dfs(int noww,int id){
	if(!noww) return 1;
	if(id==0&&noww!=0){
		return 0;
	}
	
	if(abs(noww)>sum[id]) return 0;
	for (;id>=1;id--){
		if (dfs(noww-w[id], id-1)||dfs(noww+w[id], id-1)){
			return 1;
		}
	}
	return 0;
}
inline bool cmp(int x,int y){return x<y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	sort(w+1,w+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+w[i];
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		puts(dfs(x,n)?"YES":"NO");
	}
	return 0;
}
