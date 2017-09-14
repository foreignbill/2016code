#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double calc(int l){
    double t1 = asin(sqrt(14.0)/8.0);
    double t2 = asin(sqrt(14.0)/4.0);
    double s2 = l * l * 1.0 / 8 * t2 * 2;
    double s1 = l * l * 1.0 / 2 * t1 * 2 - sqrt(7) / 8 * l * l; 
    return (s2 - s1)*2.0;
}

int main(){
    int T,l;
    cin>>T;
    while(T--){
        cin>>l;
        printf("%.2lf\n",calc(l));    
    }
    return 0;
} 
