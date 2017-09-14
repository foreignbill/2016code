#include <bits/stdc++.h> 
int s[100005];  
int main(){
	int n,m,a,i;
	while(~scanf("%d%d",&n,&m)){
		memset(s,0,sizeof(s));
		a=1;
		for(i=1;i<=m;i++){
			a*=10;
			while(a<n){
				a*=10;
				s[i++]=0;
			}
			s[i]=a/n;
			a%=n;
			if(!a) break;
		}
		printf("%d\n",s[m]%10);
	}
	return 0;
}
