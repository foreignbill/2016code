#include <bits/stdc++.h>

using namespace std;

int a[1111],b[1111];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        int top=1;
        while(T--){
            int n;
            scanf("%d",&n);
            for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            for(int i=1;i<=n;i++) scanf("%d",&b[i]);
            int fm=a[n],fz=b[n]; 
            for(int i=n-1;i>=1;i--){
                 int tmp=fz;
                 fz=fm*b[i];
                 fm=fm*a[i]+tmp;
            }
            int tt=gcd(fz,fm);
            printf("Case #%d: %d %d\n",top,fz/tt,fm/tt);
            top++;
        }
    }

    return 0; 
}
