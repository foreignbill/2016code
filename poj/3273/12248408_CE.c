#include <cstdio>
#include <algorithm>

#define INF 200000000

using namespace std;

int n,k,a[2000000];

bool check(int x){
	 int m0=0,k0=0;
	 for(int i=1;i<=n;i++){
	 	if(a[i]+m0<=x){
	 		m0+=a[i];
	 		continue;
	 	}
	 	m0=a[i];
	 	k0++;
	 }
	 if(m0) k0++;
	 if(k0<=k) return true;
	 return false;
}

int main(){
	scanf("%d%d",&n,&k);
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}
	int mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) {
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	
	return 0;
}