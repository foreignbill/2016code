#include <bits/stdc++.h>
using namespace std;

int n,m,value[11111],head[11111],e[11111],next[11111],a,b;
int dp[255][255];
bool v[11111];

int dfs(int id){
	v[id]=1;
	for(int t=head[id];t;t=next[t]){
		int k=e[t];
		if(v[k]==0) dfs(k);
		for(int j=m;j>=2;j--){
			for(int c=1;c<j;c++){
                if(dp[k][j-c]!=-1&&dp[id][c]!=-1)
                    dp[id][j]=max(dp[id][j],dp[id][k]+dp[k][j-c]);
            }
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m),n||m){
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&value[i]); 
			dp[i][1]=value[i];
			if(!a) continue; 
			e[i]=i;
			next[i]=head[a];
			head[a]=i;
		}
		m++;
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
			v[i]=0;
            for(int j=2;j<=m;j++){
                dp[i][j]=-1;
            }
        }
		dfs(0);
		printf("%d\n",dp[0][m]);
	} 
	
	return 0;
}
