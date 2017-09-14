#include <cstdio>
#include <cmath>
typedef long long LL;
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
} 
using namespace std; 
int main(){
    LL a,b;
    while(~scanf("%I64d%I64d",&a,&b)){
        LL k=gcd(a,b);
        a/=k;b/=k;
        if(a*a-4*b<0){
            puts("No Solution");
            continue;
        }
        LL tt=sqrt (a*a-4*b);
        LL x1 = (a - tt)/2;
        LL x2 = (a + tt)/2;
        
        
        
        if(x1+x2==a&&x1*x2==b) printf("%I64d %I64d\n",x1*k,x2*k);
        else puts("No Solution");
    }
    
    return 0;
}
