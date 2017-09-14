#include<stdio.h>
int main()
{
    char a[3],temp;
    while (scanf("%s",&a)!=EOF)
    {
        if(a[0]>a[2])
        {
            temp=a[0];
            a[0]=a[2];
            a[2]=temp;
        }
        if(a[1]>a[2])
        {
            temp=a[1];
            a[1]=a[2];
            a[2]=temp;
        }
        
        if(a[0]>a[1])
        {
            temp=a[1];
            a[1]=a[0];
            a[0]=temp;
        }
        printf("%c %c %c\n",a[0],a[1],a[2]);
    }
}
