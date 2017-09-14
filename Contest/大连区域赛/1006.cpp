#include <cstdio>
#include <algorithm>

using namespace std;

int num[111111];

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int tot=0,sai=n*(n-1)/2;
		bool pan=true;
		for(int i=1;i<=n;i++){
			 scanf("%d",num+i);
			 tot+=num[i];
		}
		if(tot!=n*(n-1)) pan=false;
		for(int i=1;i<=n;i++)
			if(num[i]%2) num[i]--; 
		sort(num+1,num+n+1);
		
		
	}
	
	return 0;
}
