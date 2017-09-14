#include<bits/stdc++.h>
using namespace std;
int a[105];
int ans[105][105];
int sum[105];
int main(){
    int T,n,x,m,len;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        sum[1]=a[1];
        for(int i=2;i<=n;i++) sum[i]=sum[i-1]^a[i];
        
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                ans[i][j] = sum[j] ^ sum[i-1];
            }
        
        scanf("%d",&m);
        for(int cnt=1;cnt<=m;cnt++){
            int min=INT_MAX;
            len=0;
            scanf("%d",&x);
            
            for(int i=1;i<=n;i++)
                for(int j=i;j<=n;j++)
                    if(abs( ans[i][j] - x ) < min){
                        min=abs( ans[i][j] - x );
                        len=j-i+1;
                    }
                    else if(abs( ans[i][j] - x ) == min){
                        if(len<j-i+1) len=j-i+1;
                    }
            printf("%d\n",len);    
        }
        puts("");
    }
    
    return 0;
} 
