#include<stdio.h>
using namespace std;
int main ()
{
    int a,b,c;
    char d;
    while(scanf("%d%d%d%d%d",&a,&d,&b,&d,&c)!=EOF)
    {
        int e=0;
        switch(b)
        {
        case 12:e+=30;
            case 11:e+=31;
            case 10: e+=30;
            case 9: e+=31;
            case 8: e+=31;
            case 7: e+=30;
            case 6: e+=31;
            case 5: e+=30;
            case 4: e+=31;
            case 3: if((a%4==0&&a%100!=0)||(a%400==0))
                     e+=29;
                    else e+=28;
            case 2: e+=31;
        }
        printf("%d\n",e+c);
    }
    return 0;
}
