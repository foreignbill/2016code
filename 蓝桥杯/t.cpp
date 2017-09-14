#include <cstdio>
#include <cmath>
#define LL long long 

using namespace std;

int n;
struct node{
	int x,y;
}p[1111];

LL get(int x1,int y1,int x2,int y2){
	return x1*y2-x2*y1;
}

LL gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	p[0].x=p[n].x;p[0].y=p[n].y;
	p[n+1].x=p[1].x;p[n+1].y=p[1].y;
	LL ans=0;
	for(int i=1;i<=n;i++) ans += get(p[i].x,p[i].y,p[i+1].x,p[i+1].y);//求总面积两倍 
	
	ans = abs(ans);
	
	for(int i=1;i<=n;i++){//斜边割矩形 
		int m=abs(p[i].x-p[i+1].x),n=abs(p[i].y-p[i+1].y);
		ans -= ( m + n ) - gcd(m,n);
	}
	
	for(int i=1;i<=n;i++){//跨立，解决多算问题。顺时针。 
		
		
	}
	
	return 0;
} 
