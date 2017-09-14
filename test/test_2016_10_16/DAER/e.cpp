#include <bits/stdc++.h>

int n,m;
int num[255];
int  map[255][255];
int dp[255][255];
bool v[255];
int dfs(int p){
    int i,j,k;
    v[p]=true;
    for(i=1;i<=num[p];i++){
        int t=map[p][i];//son 
        if(!v[t]) dfs(t);//若未访问 则跟进 
        for(j=m;j>=2;j--){//选择1个的状态不用更新了，因为是强制要加进去的，即必须先选择的
            for(k=1;k<j;k++){
                if(dp[t][j-k]!=-1&&dp[p][k]!=-1)
                    dp[p][j]=max(dp[p][j],dp[p][k]+dp[t][j-k]);
            }
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d%d",&n,&m),n||m){
        int a,b;
        dp[0][1]=0;//添加一个0号点为根节点，必取，价值为0
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            dp[i][1]=b; 
            map[a][++num[a]]=i;//边集数组
        }
        m++;//增加一个点，森林转换成树
        for(i=0;i<=n;i++){
            dp[i][0]=0;
			v[i]=0;
            for(j=2;j<=m;j++){
                dp[i][j]=-1;
            }
        }//初始化 
        dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}

