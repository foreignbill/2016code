#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m,k;

struct matrix{
	int a[33][33];
};

matrix a,E,ans;

matrix mul(matrix a,matrix b){
	matrix c;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++){
	   	     c.a[i][j]=0;
	   	  for(int k=1;k<=n;k++)
	   	  	 c.a[i][j]+=a.a[i][k]*b.a[k][j];
	   	  c.a[i][j]%=m;
	   }
	return c;
}

matrix add(matrix a,matrix b){
	matrix c;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++){
	   	   c.a[i][j]=a.a[i][j]+b.a[i][j];
	   	   c.a[i][j]%=m;
	   }
	return c;
}

matrix cf(int k){
	if(k==1) return a;
	matrix tmp=cf(k/2);
	tmp=mul(tmp,tmp);
	if(k&1)
	  tmp=mul(tmp,a);
	return tmp;
}

matrix calc(int k){
	if(k==1) return a;
	matrix tmp,tt;
	tmp=calc(k>>1);
	if(k&1){
	  tt=cf(k/2+1);
	  tmp=add(tmp,mul(tmp,tt));
	  tmp=add(tt,tmp);
	}
	else{
	  tt=cf(k/2);
	  tmp=add(tmp,mul(tmp,tt));
	}
	return tmp;
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++){
	   	  scanf("%d",&a.a[i][j]);
	   	  a.a[i][j]%=m;
	   	  E.a[i][j]=(i==j);
	   }
	ans=calc(k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++) printf("%d ",ans.a[i][j]%m);
		printf("%d\n",ans.a[i][n]%m);
	}
	
	return 0;
}