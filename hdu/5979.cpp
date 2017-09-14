#include <cstdio>
#include <cmath>
using namespace std;
const double pi=atan(1.0)*4.0;
int main(){
    int n,l;
    while(~scanf("%d%d",&n,&l)){
        int angles;
        double ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&angles);
            double rad;
            rad= angles * 1.0 / 180 * pi;
            ans+= 0.5 * l * l * sin(rad);
        }
        printf("%.3lf\n",ans);
    }
    
    return 0;
} 
