#include<stdio.h>
int gcd(int a,int b){ return b==0?a:gcd(b,a%b);}//最大公约数 
int main(){
   int n,i;
   while (scanf("%d",&n)!=EOF){
    	int x,y;
    	int ans=0;
    	scanf("%d%d",&x,&y);
    	x=x/gcd(x,y)*y;
    	for(i=3;i<=n;i++){
    		scanf("%d",&y);
    		x=x/gcd(x,y)*y;
    	}
    	printf("%d\n",x);
	}
	return 0;
}
