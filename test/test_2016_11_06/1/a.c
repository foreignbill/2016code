#include <stdio.h>
int main(){
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		puts(x<y?"NO BRAINS":"MMM BRAINS");
	}
	return 0;
} 
