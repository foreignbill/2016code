#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int N,n,m; 

int main(){
	freopen("d.in","r",stdin);
	scanf("%d",&N);
	while(N--){
		int id=0;
		while(cin>>n>>m,n||m){
			int ans=0;
			for(int a=1;a<n;a++)
				for(int b=a+1;b<n;b++)
					if ((a*a+b*b+m)%(a*b)==0) ans++;
			printf("Case %d: %d\n",++id,ans);
		}
		if(N) puts("");
	}
	return 0;
} 
