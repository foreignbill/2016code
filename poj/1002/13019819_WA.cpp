#include <stdio.h>
#include <stdlib.h>
           
int map(char ss)   //预处理字母和数字的对应关系
{ switch(ss)
     { 
          case 'A':case'B':case'C': 
                return(2);
          break;
          case 'D':case 'E':case 'F': 
                return(3);
          break;
          case 'G':case'H':case'I': 
                return(4);
          break;
          case 'J':case'K':case'L': 
                return(5);
          break;
          case 'M':case'N':case'O': 
                return(6);
          break;
          case 'P':case'R':case'S': 
                return(7);
          break;
          case 'T':case'U':case'V': 
                return(8);
          break;
          case 'W':case'X':case'Y': 
                return(9);
          break;
     }
}
int cmp(const void*a,const void*b)//快排自定义cmp 
{
    return *(int*)a-*(int*)b;
}
int main()
{
                        
  freopen("1002.txt","r",stdin);
  int n,ii,i;  
  scanf("%d",&n);
  int a[200000];
  for (ii=0;ii<n;ii++) 
  {  
     char s[256];
     scanf("%s\n",&s);
     int ai;
     ai=1;
     i=0;
     while (ai<=7) { 
                
          if ((s[i]<='9')&&(s[i]>='0')) {a[ii]=a[ii]*10+s[i]-'0';ai++;} else
          if ((s[i]<='Z')&&(s[i]>='A')) {a[ii]=a[ii]*10+map(s[i]);ai++;}
          i++;
          }
  }//把输入号码转换为数字 
  qsort(a,n,sizeof(int),cmp);
  int j;
  i=0;
  int jude;
  jude=0;
  while (i<n-1){              //输出
        j=i;
        while (a[i]==a[i+1]) i++;
        if (i!=j) {printf("%03d-%04d %d\n",a[i]/10000,a[i]%10000,i-j+1);jude=1;}
        i++;
        }
  if (jude==0) printf("No duplicates.\n");
  return 0;
}