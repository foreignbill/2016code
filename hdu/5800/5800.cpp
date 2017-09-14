#include <bits/stdc++.h>

#define LL long long 

using namespace std;

int n,s,a[1111];
int dp[1111][1111][3][3];

const int MOD = 1000000007; 

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0,sizeof dp);
		dp[0][0][0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=s;j++)
			    for(int s1=0;s1<=2;s1++)
			    	for(int s2=0;s2<=2;s2++){
			    		dp[i][j][s1][s2]=(dp[i][j][s1][s2]+dp[i-1][j][s1][s2])%MOD;
			    		if(j-a[i]>=0) dp[i][j][s1][s2]=(dp[i][j][s1][s2]+dp[i-1][j-a[i]][s1][s2]) % MOD;
			    		if(s1&&j-a[i]>=0) dp[i][j][s1][s2]=(dp[i][j][s1][s2] + dp[i-1][j-a[i]][s1-1][s2]) % MOD;
			    		if(s2) dp[i][j][s1][s2]=(dp[i][j][s1][s2]+dp[i-1][j][s1][s2-1]) % MOD;
			    	}
		LL ans=0;
		for(int i=0;i<=s;i++) ans=(ans + dp[n][i][2][2]) % MOD;
		ans=(ans + ans) % MOD;
		ans=(ans + ans) % MOD;
		printf("%d\n",ans);
	}
	
	
	return 0;
}
