#include <bits/stdc++.h>
#define LL long long 
using namespace std;
char S[111111];
int main(){
    int T;
    scanf("%d\n",&T);
    while(T--){
        LL ans=0;
        gets(S);
        int len=strlen(S);
        int id=0;LL l;
        while(id<len){
            l=0;
            while(S[id]=='q') id++,l++;
            ans+=(l+1)*l/2;
            id++;
        }
        printf("%I64d\n",ans);
    }
    
    return 0;
}
