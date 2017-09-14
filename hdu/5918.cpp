#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N],b[N],f[N],vis[N];
int n,m,p,ans;
void sol(){
 for (int k=0;k<n;k++){
  int j=0;
  for (int i=k;i<n;i+=p){
   if (a[i]!=b[j]) break;
   else j++;
   if (j==m){ ans++;break;}
  }
 }
}
int main()
{
 int T;
 scanf("%d",&T);
 for (int ca=1;ca<=T;ca++){
  scanf("%d%d%d",&n,&m,&p);
  for (int i=0;i<n;i++) scanf("%d",a+i);
  for (int i=0;i<m;i++) scanf("%d",b+i);
  ans=0;sol();
  printf("Case #%d: %d\n",ca,ans);
 }
}
