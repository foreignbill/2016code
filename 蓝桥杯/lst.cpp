#include <bits/stdc++.h>
#define LL long long 
using namespace std;
struct treetype{
	int l,r,s;
}T[2222222];
int n,tot[111111],a[111111];

void build(int l,int r,int tp){
	T[tp].l=l;
	T[tp].r=r;
	T[tp].s=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,tp+tp);
	build(mid+1,r,tp+tp+1);
}

void add(int id,int tp,int x){
	if(T[tp].l==T[tp].r){
		T[tp].s+=x;
		return; 
	}
	int mid=(T[tp].l+T[tp].r)>>1;
	if(id<=mid) add(id,tp+tp,x);
	if(id> mid) add(id,tp+tp+1,x);
	T[tp].s=T[tp+tp].s+T[tp+tp+1].s; 
}

int query(int l,int r,int tp){
	if(l<=T[tp].l&&T[tp].r<=r) return T[tp].s;
	int ans=0;
	int mid=(T[tp].l+T[tp].r)>>1;
	if(l<=mid) ans+=query(l,r,tp+tp);
	if(r> mid) ans+=query(l,r,tp+tp+1);
	return ans;
}

int main(){
	scanf("%d",&n);
	int N=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
		if(a[i]>N) N=a[i];
	}
	build(1,N,1);
	for(int i=1;i<=n;i++){
		tot[i]+=query(a[i]+1,N,1);//before bigger
		add(a[i],1,1);
	}
	build(1,N,1);
	for(int i=n;i>=1;i--){
		tot[i]+=query(1,a[i]-1,1);//after smaller
		add(a[i],1,1);
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		ans = ans +(LL)(tot[i]+1)*tot[i]/2;
	}
	
	printf("%I64d\n",ans);
	return 0;
} 
