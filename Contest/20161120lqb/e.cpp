# include <stdio.h>
# include <string.h>
int n, m;
int dp[50],flag[50];
int g[50];
int main(){
	int i, j, k, num, flage;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		flag[x]++;
	}
	if(flag[1]==0) dp[1]=1;
	if(flag[2]==0) dp[2]=1;
	for(int i=3;i<=n;i++){
		if(flag[i]==0) dp[i]=dp[i-1]+dp[i-2];
		else dp[i]=0; 
	} 
	printf("%d\n",dp[n]);
	return 0;
}
