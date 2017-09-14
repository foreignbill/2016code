#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[1000000],tmp[1000000];

int main(){
	freopen("d.in","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		sort(num+1,num+1+n);
		int sum=0;
		bool pan=true;
		
		for(int i=1;i<=n;i++) sum+=num[i];
		if(sum!=(n-1)*n) pan=false;
		
		if(num[n]>(n-1)*2) pan=false;
		for(int i=n;i>=1;i--) tmp[i]=2*(i-1)-num[i];
		
		int t=0;
		for(int i=1;i<=n;i++) t+=tmp[i];
		
		if(t!=0) pan=false;
		
		if(pan) puts("T");
		if(!pan)puts("F");
	}
	
	return 0;
} 
