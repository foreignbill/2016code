#include <cstdio>
#include <cmath>
const double eps = 1e-8;
const double pi = acos(-1.0);
int dsgn(double x){return x < -eps ? -1 : x > eps;}

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
	freopen("output2.txt","w",stdout);
    int T;  scanf("%d", &T);
    while(T--){
        double x0, x1, y0, y1, r;
        scanf("%lf%lf%lf%lf%lf", &x0, &y0, &x1, &y1, &r);
        x1 -= x0, y1 -= y0;
        double l = sqrt(x1 * x1 + y1 * y1);
        double lt = 0, rt = 1e5;
        while(dsgn(rt - lt) > 0){
            double md = (lt + rt) / 2.0;
            if(dsgn(2.0 * Area(r, md, l) - pi * r * r) >= 0)rt = md;
            else lt = md;
        }
        printf("%.4f\n", rt);
    }
    return 0;
}
