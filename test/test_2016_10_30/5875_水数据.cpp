#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int a[111111],NEXT[111111];
int main(){
    int T;
    while(~scanf("%d",&T)){
        while(T--){
            int n;
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
                scanf("%d",&a[i]);
            for(int i=1; i<=n; i++){
                NEXT[i]=-1;
                for(int j=i+1; j<=n; j++)
                    if(a[j]<=a[i]){
                        NEXT[i]=j;
                        break;
                    }
            }
            int Q;
            scanf("%d",&Q);
            while(Q--){
                int l,r;
                scanf("%d%d",&l,&r);
                int ans=a[l];
                for(int i=NEXT[l]; i<=r; i=NEXT[i]){
                    if(i==-1)break;
                    ans%=a[i];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

