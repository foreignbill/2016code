#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Matrix
{
    int v[2][2];
};


Matrix cheng(Matrix a,Matrix b)
{
  Matrix c;
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
        c.v[i][j]=0;
        for(int k=0;k<2;k++)
        c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%10000;
    }
  }
  return c;
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        if(n==0)
        {
        cout<<'0'<<endl;  continue;
        }
        if(n==1)
        {
        cout<<'1'<<endl;  continue;
        }


        Matrix aa,bb;
        aa.v[0][0]=aa.v[0][1]=aa.v[1][0]=1;
        aa.v[1][1]=0;
        bb.v[0][0]=bb.v[1][1]=1;
        bb.v[0][1]=bb.v[1][0]=0;
        while(n)
        {
          if(n&1)
          {
              bb=cheng(aa,bb);
          }
           n=n>>1;
           aa=cheng(aa,aa);
        }
        int ans=bb.v[1][0];
        cout<<ans<<endl;
    }
    return 0;
}