#include <cstdio>
#include <cstring>

using namespace std;

long long n,m;

int main(){
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        if(n*n/4<=m)puts("T");
        else puts("F"); 
    }
    return 0;
} 
