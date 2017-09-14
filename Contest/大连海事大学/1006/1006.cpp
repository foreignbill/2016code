#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const LL maxn=1e5+5;
LL A[maxn],s[maxn];
LL Inv[maxn];
void getINV(){ 
    Inv[1]=1;
    for(LL i=2; i<maxn; i++)
        Inv[i] = (mod-mod/i)*Inv[mod%i]%mod;
}
void init(){
    s[1]=0;
    for(LL i=2;i<maxn;i++)
       s[i]=s[i-1]+i;
    A[0]=1;
    for(LL i=1;i<maxn;i++)
        A[i]=A[i-1]*i%mod;
    getINV();
}

int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        int pos;
        LL x,sum;
        scanf("%lld",&x);
        LL n=(LL)(sqrt(2*x+2));
        for(int i=n;i>=1;i--)
        if(s[i]<=x){
            pos=i;
            break;
        }
        if(x==1) { puts("1"); continue; }
        if(s[pos]==x) { printf("%lld\n",A[pos]); continue; }
        if(s[pos]+pos-1>=x){
            LL tot=s[pos]+pos-1-x;
            sum=(A[pos+1]*Inv[tot+2])%mod;
        }
        else{
            LL tot=s[pos+1]-2+pos-1-x;
            sum=((A[pos+2]*Inv[2])%mod)*Inv[tot+3]%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
