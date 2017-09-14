#include <iostream>
#include <cstdlib>
using namespace std;
struct DNA{
  string s;     
  int value;
};
int cmp(const DNA *a, const DNA *b)  {   return (a->value-b->value);   }    
int main()
{
    int n,m;
    while(cin>> m >>n)
    {
         DNA it[n];      
         for(int i=0;i!=n;i++)
         {
            cin >> it[i].s;
            it[i].value = 0;
            for(int j=0;j!=m;j++)
                for(int k=j+1;k!=m;k++)
                     if(it[i].s[j]>it[i].s[k])   it[i].value++;
         }
         qsort(it,n,sizeof(DNA), (int (*)(const void *, const void *))cmp);
         for(int i=0;i!=n;i++)
              cout << it[i].s <<endl ;              
    }
    return 0;    
}