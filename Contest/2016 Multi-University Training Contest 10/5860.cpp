#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 3000010; 
int ans[MAXN],f[MAXN],a[MAXN],LEFT[MAXN];
int T,n,k,q,x;

void solve(){
	int t = n;
	int tot = 0;
	LEFT[0] = 0;
	while(t){
		tot++;
		LEFT[tot] = LEFT[tot-1]+(t-1)/k+1;
		t-=(t-1)/k+1;
	}
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		f[i]=(i%k)?f[i-i/k-1]+1:0;
		a[i]=(i%k)?a[i-i/k-1]:i/k+1;
	}
	
	for(int i=0;i<n;i++){
		int t=LEFT[f[i]]+a[i];
		ans[t]=i;
	}
}

int main(){
	cin>>T;
	while(T--){
		memset(ans,0,sizeof(ans)); 
		scanf("%d%d%d",&n,&k,&q);
		solve();
		for(int i=1;i<=q;i++){
			scanf("%d",&x);
			printf("%d\n",ans[x]+1);
		} 
	}
	return 0;
} 
