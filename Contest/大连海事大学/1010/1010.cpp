#include <cstdio>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)){
		long long tt;
		int cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%I64d",&tt);
			
			if(tt%256==97) cnt++;
			tt/=256;
			
			if(tt%256==97) cnt++;
			tt/=256;
			
			if(tt%256==97) cnt++;
			tt/=256;
			
			if(tt%256==97) cnt++;
			tt/=256;
			
			if(tt%256==97) cnt++;
			tt/=256;
			
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
