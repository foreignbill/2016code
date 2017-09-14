/**************************************************************
    Problem: 1008
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:804 kb
****************************************************************/
 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define MOD 100003 
 
using namespace std; 
 
typedef long long LL; 
 
LL n,m; 
 
LL power(LL p,LL n) { 
    LL ans=1; 
    p%=MOD; 
    while(n) { 
        if(n&1)  ans=ans*p%MOD; 
        p=p*p%MOD,n>>=1; 
    } 
    return ans; 
} 
int main() { 
    scanf("%lld %lld",&n,&m); 
    printf("%lld\n",(power(n,m)-n%MOD*power(n-1,m-1)%MOD+MOD)%MOD); 
    return 0; 
}
