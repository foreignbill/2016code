#define pi acos(-1.0)
struct node{
 double x£»
 double y;
 double r;
} c[maxn];
double area(int i,double r1,int j£¬double r2){
	double d=sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-  c[j].y)*(c[i].y-c[j].y));
	if(r1>r2){
		double temp=r1;
		r1=r2;
		r2=temp;
	}
	if(r1+r2<=d) return 0;
	else if(r2-r1>=d) return pi*r1*r1;
	else {
	double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
	double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
	return (a1*r1*r1+a2*r2*r2-r1*d*sin(a1));
	}
}
