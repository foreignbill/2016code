#include<stdio.h>
                                           
int main(){
                                            
    float c;
    scanf("%f",&c);
    while (c!=0){          
          int i;
          i=0;
          float cc;
          cc=0;
          do {              
              i++;
              cc=cc+(double)1/(i+1); //这里做运算要小心
              } while (cc<c);
          printf("%d card(s)\n",i);
          scanf("%f",&c);
    }
                                             
    return 0;
}