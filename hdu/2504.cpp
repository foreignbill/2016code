#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
#include <queue>
#define MAX 1000000
using namespace std;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main(){
    int n,a,b,c,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        a/=b;
        for(i=2;i<=MAX;i++){
            if(gcd(i,a)==1){
                c=i*b;
                break;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
