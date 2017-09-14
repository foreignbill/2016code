#include <cstdio>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=2;i<=n;i++){
			bool pan=1;
			for(int j=2;j*j<=i;j++) if(i%j==0) pan=0;
			if(pan) ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
