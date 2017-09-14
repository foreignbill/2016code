#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m,k;

struct matrix{
	int a[50][50];
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
	if(k%2==1){
		tmp=mul(tmp,tmp);
		tmp=mul(tmp,a);
		return tmp;
	}
	if(k%2==0){
	    tmp=mul(tmp,tmp);
	    return tmp;
	}
}


matrix calc(int k){
	if(k==1) return a;
	matrix tmp,tt;
	tmp=calc(k/2);
	if(k%2==1){
	  tt=cf(k/2+1);
	  tmp=add(tmp,mul(tmp,tt));
	  tmp=add(tmp,tt);
	}
	else{
	  tt=cf(k/2);
	  tmp=add(tmp,mul(tt,tmp));
	}
	return tmp;
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++){
	   	  scanf("%d",&a.a[i][j]);
	   	  E.a[i][j]=(i==j);
	   }
	ans=calc(k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++) printf("%d ",ans.a[i][j]%m);
		printf("%d\n",ans.a[i][n]%m);
	}
	
	return 0;
}