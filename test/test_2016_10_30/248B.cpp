#include <bits/stdc++.h>

int i,p,n;

int main(){
	while(scanf("%d",&n)!=EOF){
	     if(n<=3) printf("%d\n",n<=2?-1:210);
	     else{
		     printf("1");
		     for(p=50,i=1;i<=n-4;++i)  printf("0"),p=p*10%210;
		     printf("%03d\n",p);
	     }
	}
	return 0;
}
