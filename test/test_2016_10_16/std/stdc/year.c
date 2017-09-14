#include <stdio.h>

int main(){
	freopen("year.in","r",stdin);
	freopen("year.out","w",stdout);
	int year;
	scanf("%d",&year);
	if(year%100!=0) 
		if(year%4==0) printf("Yes\n");
		else printf("No\n");
	else if(year%400==0) printf("Yes\n");
		 else printf("No\n");
	return 0;
} 
