#include <bits/stdc++.h>
#define LL long long 

using namespace std;

int main(){
    int T;
    cin>>T;int id=1;
    while(T--){
        LL n;
        scanf("%I64d",&n);
        LL ans=(n+2)*(n-1)/2;
        printf("Case #%d: %I64d\n",id++,ans);
    }
    
    return 0;
} 
