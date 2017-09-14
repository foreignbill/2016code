#include <bits/stdc++.h>

int main(){
	int i,x,y;
	i=x=y=0;
	do{
		++i;
		if(i%2!=0){
			x+=i;
			i++; 
		}
		y=y+i++;
	}while(i<=7);
	printf("%d %d",x,y);
	return 0;
}
