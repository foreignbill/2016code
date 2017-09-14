#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
const double pi = 4.0 * atan(1.0);
int r,v1,v2,k;
int main(){
    int T;
	scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d",&r,&v1,&v2,&k);
        double left=k,right=2*pi*r,ans;
        double TMAX=right;
        while (left<=right){
            double mid=(left+right)/2;
            double f=TMAX-mid;
            if(f>=mid) f=mid;
            double angle=pi*(f/TMAX);
            double t = 2 * r * ( sin ( angle ) );
            if (((mid-k)/v1)<(t/v2)){
            	left=mid+0.0001;
            	ans=mid;
            }
            else right=mid-0.0001;
         }
        printf("%.0f\n",right);
    }
    return 0;
}
