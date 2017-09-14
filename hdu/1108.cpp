#include <cstdio>

using namespace std;

int gcd(int a,int b){
    if(a%b!=0) return gcd(b,a%b);
    if(a%b==0) return b;
}

int main(){
    int a,b;
    
    while(scanf("%d%d",&a,&b)!=EOF)    printf("%d\n",a*b/gcd(a,b));
    
    return 0;
}
