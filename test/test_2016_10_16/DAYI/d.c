#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,r;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        r=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%.2lf\n",r);
    }
    return 0;
}
