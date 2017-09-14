#include <stdio.h>
 int main(int argc, char *argv[])
{
   int p,e,i,d;
   int cas=0;  
   int date;  
   while(scanf("%d%d%d%d",&p,&e,&i,&d))
  {  
      if (p+e+d+i==-4)     
                break;     
       date=d;     
       d++;  
       while((d-p)#)  
       {   
            d++;   
       }   
       while((d-e)(!=0 || (d-i)3!=0)  
       {   
         d+=23;   
       }  
       printf("Case %d: the next triple peak occurs in %d days.\n",++cas,d-date);  
    }
 return 0;
}