#include <cstdio>
#include <iostream> 
#include <algorithm>
#include <cmath>
#include <cstring>
#define LL long long 

using namespace std;

LL n,key[555],v[555];
LL f[555][555];

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			cin>>n;
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++) cin>>key[i];
			for(int i=1;i<=n;i++) cin>>v[i];
				
			for(int i=1;i<=n-1;i++) if(gcd(key[i],key[i+1])!=1) f[i][i+1]=v[i]+v[i+1];
			
			for(int l=2;l<n;l++)
				for(int i=1;i<=n-l;i++){
					f[i][i+l]=max( f[i][i+l-1] , f[i+1][i+l] );
					if(gcd(key[i],key[i+1])!=1)
						f[i][i+l]=max(f[i][i+l] , f[i+2][i+l] + v[i] + v[i+1] );				
				} 
			cout<<f[1][n]<<endl;
		}
	}
	
	return 0;
}
