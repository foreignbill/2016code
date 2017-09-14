#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define LL long long

using namespace std;

int main(){
	LL ans,l,r;
	while(scanf("%I64d%I64d",&l,&r)!=EOF){
	 	LL tmp=(r-max(l,1LL))/2+1;
	 	ans=max(tmp,2LL);
	 	if(r<=2) ans=1;
	 	if(r<=1) ans=0;
	 	printf("%I64d\n",ans);
	}
	
	return 0;
} 
