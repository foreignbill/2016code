#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int f[200055][25],num[200055],k,mid;

int log2(int x){
    return floor( log( ( double )x ) / log( 2.0 ));
}

int main(){
    while(1){
      memset(f,0,sizeof(f));
      memset(num,0,sizeof(num));
      int n,q;
      scanf("%d",&n);
      if(n==0) break;
      scanf("%d",&q);
	  for(int i=1;i<=n;i++) scanf("%d",num+i);
	  f[1][0]=1;
	  for(int i=2;i<=n;i++)
	    if (num[i]!=num[i-1]) f[i][0]=1;
	    else f[i][0]=f[i-1][0]+1;
	  for(int i=n;i>=1;i--)
	     for(int j=1;j<=log2(n);j++){
		    int k=i+(1<<(j-1));
		    if(k>n) f[i][j]=f[i][j-1];
		    else f[i][j]=max(f[i][j-1],f[k][j-1]);
		 }
	  for(int cnt=1;cnt<=q;cnt++){
	  	 int aa,bb;
	  	 scanf("%d%d",&aa,&bb);
		 int ax,bx;
		 ax=aa;
		 bx=bb;
		 int left,right;
		 left=1;right=n;
		 while(left<=right){
		   mid=(left+right)>>1;
		   if(num[mid]>=num[aa]) right=mid-1;else left=mid+1;
		 }
		 int ll,rr;
		 ll=left;
		 left=1;right=n;
		 while(left<=right){
		   mid=(left+right)>>1;
		   if(num[mid]>num[aa]) right=mid-1;else left=mid+1;
		 }
		 rr=right;
		 int ans=0;
		 if(num[bx]!=num[ax]){
		   aa=rr+1;
		   bb=bx;
		   k=log2(bb-aa+1);
		   ans=max(f[aa][k],f[bb-(1<<k+1)][k]);
		 }
		 aa=ll;
		 if(num[bx]==num[rr])
		   rr=bx;
		   bb=rr-ax+aa;
		   k=log2(bb-aa+1);
		   ans=max(max(f[aa][k],f[bb-(1<<k+1)][k]),ans);
		printf("%d\n",ans);
	  }
    }
	return 0;
}