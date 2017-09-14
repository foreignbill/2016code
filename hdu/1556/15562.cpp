#include <bits/stdc++.h>
using namespace std;

struct treetype{
	int l,r,w,delta;
}T[266666];

int n,m,sum[266666],l,r;

int build(int id,int l,int r){
	T[id].l=l;
	T[id].r=r;
	T[id].delta=0;
	if(l==r){
		T[id].w=0;
		return 0;
	}
	int mid=(l+r)/2;
	build(id*2  ,l,mid);
	build(id*2+1,mid+1,r);
	T[id].w=T[id*2].w+T[id*2+1].w;
}

int down(int id){
	if(T[id].l==T[id].r){
		T[id].w+=T[id].delta*(T[id].r-T[id].l+1);
		T[id].delta=0;
		return 0; 
	}
	if(T[id].delta==0) return 0;
	T[id*2  ].delta+=T[id].delta;
	T[id*2+1].delta+=T[id].delta;
	T[id].w+=T[id].delta*(T[id].r-T[id].l+1);
	T[id].delta=0;
	return 0;
}

int change(int id,int l,int r,int ww){
	if(l<=T[id].l&&r>=T[id].r){
		T[id].w+=ww*(T[id].r-T[id].l+1);
		T[id].delta+=ww;
		return 0;
	}
	down(id);
	int mid=(T[id].l+T[id].r)/2;
    if (l<=mid) change(id*2,l,r,ww);
    if (mid< r) change(id*2+1,l,r,ww);
}

int query(int id,int l,int r){
	down(id);
	if(T[id].l>=l&&T[id].r<=r) return T[id].w;
	int ans=0,mid=(T[id].l+T[id].r)/2;
	if(l<=mid) ans+=query(id*2,l,r);
	if(r>mid)  ans+=query(id*2+1,l,r);
	return ans;
}

int main(){
	while(cin>>n,n){
		build(1,1,n);
		for(int i=1;i<=n;i++) scanf("%d%d",&l,&r),change(1,l,r,1);
		for(int i=1;i<=n;i++) sum[i]=query(1,1,i);
		for(int i=1;i<n;i++) printf("%d ",sum[i]-sum[i-1]);
		printf("%d\n",sum[n]-sum[n-1]);
	}
	return 0;
} 
