#include <bits/stdc++.h>
#define LL long long 
using namespace std;
LL a[111111],n;
LL famax[111111][20],famin[111111][20];

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

inline void getmin(){
	for(int i=1;i<=n;i++) famin[i][0]=a[i];
	for (LL j = 1; (1 << j) <= n; j++){
		for (LL i = 1; i + (1 << j) - 1 <= n; i++){
		    famin[i][j] = min(famin[i + (1 << (j-1))][j - 1], famin[i][j - 1]);
		}
	}
}

inline void getmax(){
	for(int i=1;i<=n;i++) famax[i][0]=a[i];
	for (LL j = 1; (1 << j) <= n; j++){
		for (LL i = 1; i + (1 << j) - 1 <= n; i++){
		    famax[i][j] = max(famax[i + (1 << (j-1))][j - 1], famax[i][j - 1]);
		}
	}
}

inline LL qmin(LL l,LL r){
	LL len = r - l + 1;
	LL k = 0;
	while((1<<(k+1))<=len) k++;
	return min(famin[l][k],famin[r-(1<<k)+1][k]);
}

inline LL qmax(LL l,LL r){
	LL len = r - l + 1;
	LL k = 0;
	while((1<<(k+1))<=len) k++;
	return max(famax[l][k],famax[r-(1<<k)+1][k]);
}

LL maxsum(LL l,LL r,LL x){
	if(r<l) return 0;
	if(l==r) return (a[l]>x);
	LL key=0;
	LL mid=(l+r)>>1;
	if( qmin(l,mid) > x ) key = key + mid - l + 1LL;
	else key += maxsum(l,mid,x);
	if( qmin(mid+1,r) > x ) key = key + r - mid;
	else key += maxsum(mid+1,r,x);
	return key;
}

LL minsum(LL l,LL r,LL x){
	if(r<l) return 0;
	if(l==r) return (a[l]<x);
	LL key=0;
	LL mid=(l+r)>>1;
	if( qmax(l,mid) < x) key = key + mid - l + 1LL;
	else key += minsum(l,mid,x);
	if( qmax(mid+1,r) < x)  key = key + r - mid;
	else key += minsum(mid+1,r,x);
	return key;
}

int main(){
	freopen("input4.txt","r",stdin);
	n=read();
	for(LL i=1;i<=n;i++) a[i]=read();
	getmin();getmax();
	LL ans=0;
	for(LL i=1;i<=n;i++){
		LL t = maxsum(1,i-1,a[i]) + minsum(i+1,n,a[i]);
		LL tmp;
		if(t&1) tmp = (t+1)/2*t;
		else tmp=t/2*(t+1);
		ans += tmp; 
	}
	
	cout<<ans<<endl;
	return 0;
} 
