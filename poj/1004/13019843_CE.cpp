#include<stdio.h>
using namespace std;
int main()
{
      double now,tot=0;
      for(int i=0;i<12;i++)
      {
            scanf("%lf",&now);
            tot+=now;
      }
      printf("$%.2f\n",tot/12.0);
      return 0;
}