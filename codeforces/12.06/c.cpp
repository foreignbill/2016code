#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>

#define LL long long 

using namespace std;

int a[1010];
int len[1010];

LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}

LL lcm(LL a,LL b){
	return a*b/gcd(a,b);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	
	for(int i=1;i<=n;i++){
		int t=1,x=a[i];
		while(1){
			x=a[x];
			if(x==i){
				t++;
				if(t%2==0) t=t/2;
				len[i]=t;
				break;
			}
			t++;
			if(t>n) break;
		}
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(len[i]==0){
			ans=-1;
			break;
		}
		if(ans==0){
			ans = len[i];
			continue;
		}
		ans = lcm(ans,len[i]);
	}
	cout<<ans<<endl;
	return 0;
} 
