#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long 
using namespace std;

int main(){
    char st[1111];
    while(scanf("%s",st)!=EOF){
        int len = strlen(st);
        if(len>10){
            puts("TAT");
            continue;
        }
        LL x=0;
        for(int i=0;i<len;i++) x = x*10+st[i]-'0';
        if(x>=4294967296||x==0){
            puts("TAT");
            continue;
        }
        int k = 0;
        while(x!=1){
            x = (int)sqrt(x);
            k++;
        }
        printf("%d\n",k);
    }
    return 0;
} 
