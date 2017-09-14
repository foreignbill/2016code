#include <cstdio>

using namespace std;

int a[111111];
int b[111111];

bool check(int k){
	
	
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int N,T;
			scanf("%d%d",&N,&T);
			for(int i=1;i<=n;i++) scanf("%d",a+i);
			int l=1,r=N;
			while(l+1<=r){
				int mid=(l+r)/2;
				if(check(mid)) r=l;
				else l=r;
			}
		}
	}
	
	return 0;
} 
