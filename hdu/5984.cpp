#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    double a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf",&a,&b);
        if(a<=b)
            printf("0.000000\n");  
        else
            printf("%.6lf\n",log(a/b)+1);
    }
    return 0;
}
