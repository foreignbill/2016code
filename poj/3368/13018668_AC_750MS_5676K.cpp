#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
int n,q;  
struct node{  
    int l,r;  
    int amax,lmax,rmax;  
}tree[300100];  
int a[100100];  
void build(int s,int t,int id){  
    tree[id].l=s;  
    tree[id].r=t;  
    if(s==t){  
        tree[id].amax=tree[id].lmax=tree[id].rmax=1;  
        return ;  
    }  
    int mid=(s+t)>>1;  
    build(s,mid,id*2);  
    build(mid+1,t,id*2+1);  
    int tem;  
    if(a[tree[id*2].r]==a[tree[id*2+1].l])  
        tem=tree[id*2].rmax+tree[id*2+1].lmax;  
    else  
        tem=0;  
    tree[id].amax=max(max(tree[id*2].amax,tree[id*2+1].amax),tem);  
    tree[id].lmax=tree[id*2].lmax;  
    if(tree[id*2].lmax==mid-s+1 && a[tree[id*2].r]==a[tree[id*2+1].l])      
        tree[id].lmax+=tree[id*2+1].lmax;  
    tree[id].rmax=tree[id*2+1].rmax;  
    if(tree[id*2+1].rmax==t-mid && a[tree[id*2].r]==a[tree[id*2+1].l])          
        tree[id].rmax+=tree[id*2].rmax;  
}  
int query(int s,int t,int id){  
    if(tree[id].l==s && tree[id].r==t)  
        return tree[id].amax;  
    int mid=(tree[id].l+tree[id].r)>>1;  
    if(s>mid)  
        return query(s,t,id*2+1);  
    else if(t<=mid)  
        return query(s,t,id*2);  
    else{  
        int a1=query(s,mid,id*2);  
        int a2=query(mid+1,t,id*2+1);  
        int a3=0;  
        if(a[tree[id*2].r]==a[tree[id*2+1].l])  
            a3=min(tree[id*2].rmax,mid-s+1)+min(tree[id*2+1].lmax,t-mid);   
        return max(max(a1,a2),a3);  
    }  
}  
int main(){  
    int i,j,u,v;  
    while(scanf("%d",&n)){  
        if(n==0)break;  
        scanf("%d",&q);  
        for(i=1;i<=n;i++)  
            scanf("%d",&a[i]);  
        build(1,n,1);  
        for(i=1;i<=q;i++){  
            scanf("%d %d",&u,&v);  
            printf("%d\n",query(u,v,1));  
        }  
    }  
}  