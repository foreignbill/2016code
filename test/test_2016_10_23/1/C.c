#include<stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
	 	int m;
	 	scanf("%d",&m);
	 	int sigh=1;
	 	double ans=0;
	 	int now=1;
	 	for (j=1;j<=m;j++){
	 	 	double xx=1.0/now;
	 	 	ans+=sigh*xx;
			now++; 
			sigh=-sigh; 
	 	 }
	 	 printf("%.2lf\n",ans);
	 }
	 return 0;
}

