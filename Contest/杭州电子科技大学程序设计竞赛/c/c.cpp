#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int solve(int k){
	int ans = k/10 * 4;
	int tmp = k%10;
	if(tmp==0) return ans;
	if(tmp<=3) ans+=2;
	else if(3<tmp&&tmp<=6) ans+=3;
	else ans+=4;
	return ans;
}

int main(){
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int tmp1=m/3,tmp2=m%3;
		int ans = m/3 + solve(m%3 + n - m);
		
		if(tmp2){
			int ans2 = m/3+1 + solve(n-m);
			if(ans2<ans) ans=ans2;
		} 
		
		for(int i=1;i<=10;i++){
			if(m/3-i<0) break;
			int t = (m/3 - i + solve(m%3 + 3*i + n - m));
			if(ans>t) ans = t;  
		}
		printf("%d\n",ans); 
	} 
	
	return 0;
} 
