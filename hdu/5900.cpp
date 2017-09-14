#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int n;
LL  sum[1000],a[1000],b[1000];
LL  g[302][302],dp[302][302];

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(sum,0,sizeof sum);
        memset(g,0,sizeof g);
        memset(dp,0,sizeof dp);
        
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%I64d",&b[i]),sum[i]=sum[i-1]+b[i];
        
        for(int i=1;i<=n-1;i++) if(gcd(a[i],a[i+1])>1) g[i][i+1]=1;

        for(int len=2;len<=n;len+=2){  
            for(int j=1;j+len-1<=n;j++){
                int l=j,r=j+len-1;
                if(gcd(a[l],a[r])>1 && g[l+1][r-1]) g[l][r]=1;
                if(gcd(a[l],a[l+1])>1 && g[l+2][r]) g[l][r]=1;
                if(gcd(a[r-1],a[r])>1 && g[l][r-2]) g[l][r]=1;
            }
        }
        
        for(int len=2;len<=n;len++)
            for(int j=1;j+len-1<=n;j++){
                int l=j,r=j+len-1;
                if(g[l][r]) dp[l][r]=sum[r]-sum[l-1];
                else  for(int k=l;k<r;k++)
                         dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
        
        
        printf("%I64d\n",dp[1][n]); 
    }
    return 0;
}
