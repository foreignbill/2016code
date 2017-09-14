#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
double get(long long x0,long long y0,long long x1,long long y1) {
	return (double)sqrt( (x1-x0)*(x1-x0)*1.0 + (y1-y0)*(y1- y0)*1.0 );
}
int dsgn(double x){return x < -eps ? -1 : x > eps;}
double area(long long x0,long long y0,double r1,long long x1,long long y1,double r2){
	double d =  get(x0,y0,x1,y1);
	double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
	double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
	return (a1*r1*r1+a2*r2*r2-r1*d*sin(a1));
}
double Area(double r, double R, double l){
    if(dsgn(l - r - R) >= 0) return 0;
    else if(dsgn(l - fabs(r - R)) <= 0){
        if(r > R) r = R;
        return pi * r * r;
    }
    double a = acos((l * l + r * r - R * R) / (2 * l * r));
    double b = acos((l * l + R * R - r * r) / (2 * l * R));
    double s1 = a * r * r, s2 = b * R * R;
    double S1 = r * r * sin(a) * cos(a), S2 = R * R * sin(b) * cos(b);
    return s1 + s2 - S1 - S2;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long x0,y0,x1,y1,r;
		cin>>x0>>y0>>x1>>y1>>r;
		double s1 = pi * r * r;
		double dist = get(x0,y0,x1,y1);
		double s2 = s1 / 2.0;
		double r_=sqrt(s2/pi);
		double lr_=max(0.0,dist-r),rr_=1e5,ansr;
		while(dsgn(rr_-lr_)>0){
			double midr_=(lr_+rr_)/2.0;
			double s_=area(x0,y0,r,x1,y1,midr_);
			if(dsgn(2.0 * Area(r, midr_, dist) - pi * r * r) < 0){
				lr_ = midr_+0.000000001;
				ansr=midr_;
			}
			else rr_=midr_-0.000000001;
		}
		printf("%.4lf\n",ansr);
	}
	return 0;
}
