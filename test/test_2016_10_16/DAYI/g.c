#include<stdio.h>
int main(){
	int n,a,b,c,i;
	double h[100];
	while(scanf("%d",&n),n){
		a=0;b=0;c=0;
		for(i=0;i<n;i++){
			scanf("%lf",&h[i]);
		}
		for(i=0;i<n;i++){
			if(h[i]>0)a++;
			if(h[i]==0)b++;
			if(h[i]<0)c++;
		}
		printf("%d %d %d\n",c,b,a);
	}
	return 0;
}
