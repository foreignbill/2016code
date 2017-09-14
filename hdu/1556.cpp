#include <bits/stdc++.h>
using namespace std;
const int N =444444;
int n,m,summ[444444];
struct linetree{
    #define lc  (t<<1)
    #define rc  (t<<1^1)
    #define mid (l[t]+r[t]>>1)
    int l[N],r[N],M,tag[N],sum[N],len[N],Set[N];

    inline void build(int n){
        M=1; while(M<n)M<<=1; M--;//get M
        memset(sum,0,sizeof(sum));
        memset(tag,0,sizeof(tag));
        memset(Set,0,sizeof(Set));
        for (int i=1+M;i<=M*2+1;i++){//leaf
            if(i<=n+M)sum[i]=0;
            l[i] = r[i] = i-M ;
            len[i]=1;
        }
        for (int t=M;t>=1;t--){//fathers
            sum[t]=sum[lc]+sum[rc];
            l[t]=l[lc], r[t]=r[rc];
            len[t]=len[lc]+len[rc];
        }
    }
    inline void down(int t){
        if (t>M){Set[t]=tag[t]=0;return ;}//leaf node
        if (Set[t]){
            sum[lc]=Set[t]*len[lc];
            sum[rc]=Set[t]*len[rc];
            Set[lc]=Set[t];
            Set[rc]=Set[t];
            Set[t] = 0;
            tag[lc]=tag[rc]=0;
        }
        if (tag[t]){
            sum[lc]+=tag[t]*len[lc];
            sum[rc]+=tag[t]*len[rc];
            tag[lc]+=tag[t];
            tag[rc]+=tag[t];
            tag[t] = 0;
        }
    }
    inline void _tag(int t,int x){
        sum[t]+=x*len[t];
        tag[t]+=x;
    }
    inline void _set(int t,int x){
        sum[t]=x*len[t];
        Set[t]=x;
        tag[t]=0;
    }
    void change(int t,int L,int R,int x){
        if (L<=l[t]&&r[t]<=R){_tag(t,x);return;}
        down(t);
        if (L<=mid)change(lc,L,R,x);
        if (mid< R)change(rc,L,R,x);
        sum[t]=sum[lc]+sum[rc];
    }
    void set(int t,int L,int R,int x){
        if (L<=l[t]&&r[t]<=R){_set(t,x);return;}//in
        down(t);
        if (L<=mid)set(lc,L,R,x);
        if (mid< R)set(rc,L,R,x);
        sum[t]=sum[lc]+sum[rc];
    }
    int query(int t,int L,int R){
        if (L<=l[t]&&r[t]<=R)return sum[t];
        down(t);
        int ans = 0;
        if (L<=mid)ans+=query(lc,L,R);
        if (mid< R)ans+=query(rc,L,R);
        return ans;
    }
}T;

int main(){
    while(cin>>n,n){
        memset(T.l,0,sizeof(T.l));
        memset(T.r,0,sizeof(T.r));
        memset(T.tag,0,sizeof(T.tag));
        memset(T.sum,0,sizeof(T.sum));
        memset(T.len,0,sizeof(T.len));
        memset(T.Set,0,sizeof(T.Set));
        memset(summ,0,sizeof summ);
        int l,r;
        T.build(n); 
        for(int i=1;i<=n;i++){ 
            scanf("%d%d",&l,&r);
            T.change(1,l,r,1);
        }
        T.change(1,1,n,0);
        for(int i=1;i<=n;i++) summ[i]=T.query(1,1,i);
        for(int i=1;i<n;i++) printf("%d ",summ[i]-summ[i-1]);
        printf("%d\n",summ[n]-summ[n-1]);
    }
    return 0;
} 
