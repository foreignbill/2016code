#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int g[555][555];
int s[555][555];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d",&g[i][j]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + g[i][j];
		
	int mx=-INT_MAX;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int k=1;k<=m;k++){
				sum = sum + s[j][k]-s[j][k-1] - (s[i-1][k]-s[i-1][k-1]);
				//printf("%d %d %d %d\n",i,j,k,sum);
				if(sum>mx) mx=sum;
				if(sum<0) sum=0;
			}
		}
	printf("%d\n",mx);
	return 0;
} 
