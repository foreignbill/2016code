#include<cstdio>
#include<cstring>
using namespace std;
int phi(int x){
    int y=x;
    for(int i=2; i*i<=x; ++i){
        if(x%i) continue;
        while(x%i==0) x/=i;
        y-=y/i;
    }
    if(x!=1) y-=y/x;
    return y;
}
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int res=0;
        for(int i=1; i*i<=n; ++i){
            if(n%i) continue;
            int j=n/i;
            if(i>=m) res+=phi(j);
            if(i!=j && j>=m) res+=phi(i);
        }
        printf("%d\n",res);
    }
    return 0;
}
