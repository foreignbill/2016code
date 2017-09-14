#include <bits/stdc++.h>
#define base 1000000
using namespace std;
int w[25];
int info[11];
bool f0[2000001],f1[2000001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++) scanf("%d",&info[i]);
	
	memset(f0,0,sizeof f0);
	memset(f1,0,sizeof f1);
	f0[base]=1;
	for(int i=1;i<=n;i++){
		memset(f1,0,sizeof(f1));
		for(int j=500;j<=1999950;j++){
			f1[j] = f0[j]|f0[j-w[i]]|f0[j+w[i]];
		}
		memcpy(f0,f1,sizeof(f0));
	}
	for(int i=1;i<=m;i++){
		if(f1[info[i]+base]==0) puts("NO");
		else puts("YES");
	}
	return 0;
}
