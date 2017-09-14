#include<iostream>
using namespace std;
int main()
{int n,m,i,j,num,a[101],b[101],t,k;

 char str[101][51],str1[51];
 cin>>n>>m;
 for(i=0;i<m;i++)
 {cin>>str[i];
 num=0;
    for(j=0;j<n-1;j++)
    for(k=j+1;k<n;k++)
  if(str[i][j]>str[i][k])
        num++;
        a[i]=num;}
   for(i=0;i<m;i++)
 {   b[i]=0;
  t=a[0];
 for(j=1;j<m;j++)
 if(t>a[j])
 {t=a[j];
 b[i]=j;}
 a[b[i]]=1250;}   
  for(i=0;i<m;i++)
   cout<<str[b[i]]<<endl;
  return 0;
}