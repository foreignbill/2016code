#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e4+5;
int T,n,m,dp[N][20];
struct ask{
  int l,r,id;
  bool operator<(const ask &rhs)const{
    return r<rhs.r;
  }
}p[N*10];
struct Seg{
  int l,r,v;
   bool operator<(const Seg &rhs)const{
    return r<rhs.r;
  }
}seg[35*N];
int erfen(int pos,int v){
  int l=1,r=pos;
  while(l<r){
    int mid=(l+r)>>1;
    int len=pos-mid+1;
    int now=pos,cur=-1;
    for(int i=13;i>=0;--i){
      if(len&(1<<i)){
        if(cur==-1)cur=dp[now][i];
        else cur=__gcd(cur,dp[now][i]);
        now-=(1<<i);
      }
    }
    if(cur<v)l=mid+1;
    else r=mid;
  }
  return (l+r)>>1;
}
int hash[35*N],tot,mat[35*N];
int res[N*10];
int c[N];
void add(int x,int t){
  for(int i=x;i<=n;i+=i&(-i))
    c[i]+=t; 
}
int get(int x){
  int ans=0;
  if(x==0)return 0;
  for(int i=x;i>0;i-=i&(-i))
    ans+=c[i];
  return ans;
}
int main(){
	freopen("d.in","r",stdin);
  while(scanf("%d%d",&n,&m)!=EOF){
    for(int i=1;i<=n;++i)
      scanf("%d",&dp[i][0]);
    for(int i=1;i<=m;++i)
      scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
    for(int k=1;(1<<k)<=n;++k)
    for(int i=n;i>1;--i){
      int j=i-(1<<k)+1;
      if(j<1)break;
      j=i-(1<<(k-1));
      dp[i][k]=__gcd(dp[i][k-1],dp[j][k-1]);     
    }
    int cnt=0;tot=0;
    for(int i=1;i<=n;++i){
      int last=-1;
      for(int j=i;j>0;--j){
        int tmp=dp[j][0];
        if(last!=-1)tmp=__gcd(tmp,last);
        last=tmp;
        ++cnt;
        seg[cnt].l=j,seg[cnt].r=i,seg[cnt].v=last;
        hash[++tot]=last;
        j=erfen(i,last);
      }
    }
    sort(hash+1,hash+1+tot);
    tot=unique(hash+1,hash+1+tot)-hash-1;
    sort(p+1,p+1+m);
    sort(seg+1,seg+1+cnt);
    memset(mat,0,sizeof(mat));
    memset(c,0,sizeof(c));
    int now=1;
    for(int i=1;i<=m;++i){
      for(;now<=cnt&&seg[now].r<=p[i].r;++now){
        int pos=lower_bound(hash+1,hash+1+tot,seg[now].v)-hash;
        if(seg[now].l>mat[pos]){
          if(mat[pos])add(mat[pos],-1);
          add(seg[now].l,1);
          mat[pos]=seg[now].l;
        }
      }
      res[p[i].id]=get(p[i].r)-get(p[i].l-1);
    }
    for(int i=1;i<=m;++i)
      printf("%d\n",res[i]);
  }
  return 0;
}
