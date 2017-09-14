#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
    int a = 1;
 
    a = -2;
    printf("%d\n",a);
 
    a = -2;
    printf("%d,%d\n",a,a--);
 
    a = -2;
    printf("%d,%d\n",a,a++);
 
    a = -2;
    printf("%d,%d,%d\n",a,a++,a--);
 
    a = -2;
    printf("%d,%d,%d\n",a,++a,--a);
 
    return 0;
}
