#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL; 

const int INF=0x3f3f3f3f;

const int N=100005;

int T,n,m,f[N][20];

struct ask{
	int l,r,id;
	inline bool operator<(const ask &rhs)const{
		return r<rhs.r;
	}
}p[N*10];

struct tangle{
	int l,r,v;
	inline bool operator<(const tangle &rhs)const{
		return r<rhs.r;
	}
}tangle[35*N];

int pow(int pos,int v){
	int l=1,r=pos;
	while(l<r){
		int mid=(l+r)>>1;
		int len=pos-mid+1;
		int now=pos,cur=-1;
		for(int i=13;i>=0;--i){
			if(len&(1<<i)){
				if(cur==-1)cur=f[now][i];
				else cur=__gcd(cur,f[now][i]);
				now-=(1<<i);
			}
		}
		if(cur<v)l=mid+1;
		else r=mid;
	}
	return (l+r)>>1;
}

int haxi[35*N],tot,mat[35*N];
int res[N*10];
int c[N];

void add(int x,int t){
	for(int i=x;i<=n;i+=i&(-i))
		c[i]+=t; 
}

inline int get(int x){
	int ans=0;
	if(x==0)return 0;
	for(int i=x;i>0;i-=i&(-i))
		ans+=c[i];
	return ans;
}

int main(){
	//freopen("d.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)
			scanf("%d",&f[i][0]);
			
		for(int i=1;i<=m;++i)
			scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
			
		for(int k=1;(1<<k)<=n;++k)
			for(int i=n;i>1;--i){
				int j=i-(1<<k)+1;
				if(j<1)break;
				j=i-(1<<(k-1));
				f[i][k]=__gcd(f[i][k-1],f[j][k-1]);		 
			}
			
		int cnt=0;tot=0;
		
		for(int i=1;i<=n;++i){
			int last=-1;
			for(int j=i;j>0;--j){
				int tmp=f[j][0];
				if(last!=-1)tmp=__gcd(tmp,last);
				last=tmp;
				++cnt;
				tangle[cnt].l=j,tangle[cnt].r=i,tangle[cnt].v=last;
				haxi[++tot]=last;
				j=pow(i,last);
			}
		}
		
		sort(haxi+1,haxi+1+tot);
		
		tot=unique(haxi+1,haxi+1+tot)-haxi-1;
		
		sort(p+1,p+1+m);
		sort(tangle+1,tangle+1+cnt);
		memset(mat,0,sizeof(mat));
		memset(c,0,sizeof(c));
		
		int now=1;
		
		for(int i=1;i<=m;++i){
			for(;now<=cnt&&tangle[now].r<=p[i].r;++now){
				int pos=lower_bound(haxi+1,haxi+1+tot,tangle[now].v)-haxi;
				if(tangle[now].l>mat[pos]){
					if(mat[pos])add(mat[pos],-1);
					add(tangle[now].l,1);
					mat[pos]=tangle[now].l;
				}
			}
			res[p[i].id]=get(p[i].r)-get(p[i].l-1);
		}
		
		for(int i=1;i<=m;++i)
			printf("%d\n",res[i]);
	}
	return 0;
}
