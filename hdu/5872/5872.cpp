#include <cstdio>

using namespace std;

int main(){
	int h,l,k;
	while(scanf("%d%d%d",&h,&l,&k)!=EOF){
		int num=k/h;
		int tt =k/(num+1);
		int e=tt+1;
		int ans=l/(k-k%e);
		if(l%(k-k%e)) ans++;
		printf("%d\n",ans);		
	}
	
	return 0;
} 
