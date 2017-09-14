#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
using namespace std;

int n,m,x,y;

int a[1005][1005],sum[1005][1005];

int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&n,&m,&x,&y);
        memset(a,0,sizeof a);
        memset(sum,0,sizeof sum);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j]; 
        
        //puts("-"); 
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=m;j++) cout<<sum[i][j]<<" ";
        //    puts("");
        //}
        //puts("-");
        int mx = -INT_MAX;
        
        for(int i=1;i<=n-x+1;i++)
            for(int j=1;j<=m-y+1;j++){
                int cas = sum[i+x-1][j+y-1] - sum[i-1][j+y-1] - sum[i+x-1][j-1] + sum[i-1][j-1]; 
                if(cas > mx) mx=cas;
                //printf("*%d*\n",cas);
            }
        printf("%d\n",mx);
    }
    return 0;
} 
