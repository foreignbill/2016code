#include<stdio.h>
int main(){
	int n,i,sum,a[1001];
	while(scanf("%d",&n),n){
		sum=0;
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		sum=sum+a[0]*6+5;
		if(n==1){
			printf("%d\n",sum);
			continue;
		}
		else{
			for(i=1;i<n;i++){
				if(a[i-1]<a[i]){
					sum=sum+(a[i]-a[i-1])*6+5;
				}
				if(a[i-1]>a[i]){
					sum=sum+(a[i-1]-a[i])*4+5;
				}
				if(a[i-1]==a[i]){
					sum=sum+5;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
