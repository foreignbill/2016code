#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int f[10000][20];

int rmqmax(int l,int r){  
    int m = (int)(log((r - l + 1) * 1.0) / log(2.0));  
    return max(f[l][m] , f[r - (1 << m) + 1][m]);  
}  


int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&f[i][0]);
	
	int m=(int)(log(n*1.0)/log(2.0));
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			f[i][j]=f[i][j-1];
			if(j + (1 << (i - 1)) <= n) f[j][i] = max(f[j][i], f[j + (1 << (i - 1))][i - 1]); 
		}
	
	printf("%d\n",rmqmax(1,n));
	
	return 0;
}

