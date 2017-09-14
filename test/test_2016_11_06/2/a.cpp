#include <cstdio>
#define LL long long
#define MOD 9973
int exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL tmp=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return tmp;
}

int main(){
	LL T;
	scanf("%I64d",&T);
	while(T--){
		LL a,b,x,y;
		scanf("%I64d%I64d",&a,&b);
		exgcd(b,9973,x,y);
		LL ans=(a%MOD) * (x%MOD + MOD) % MOD;
		printf("%I64d\n",ans);
	}
	
	return 0;
}
