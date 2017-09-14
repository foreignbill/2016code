#include <stdio.h>

int main(){
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	int flag=1;
	for(i=2;i*i<=n;i++){
		if(n%i) continue;
		flag=0;
		break;
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;
}
