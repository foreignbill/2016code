#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int a[10000],f[10000];
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	f[1]=1;
	for(int i=2;i<=n;i++){
		int max=0;
		for(int j=1;j<i;j++)
			if(a[j]<a[i]&&max<f[j]) max=f[j];
		f[i]=max+1;	
	}
	int max=0;
	for(int i=1;i<=n;i++) if(max<f[i]) max=f[i];
	printf("%d\n",max); 
 	return 0;
} 
