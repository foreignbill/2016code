#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
#define LL long long 

using namespace std;

const int MAXN = 100005;

struct node{
    int tp,x,y,y2;
}info[MAXN*2];
int a[MAXN*2],sum[MAXN*2],Maxn;
map<int,int> mp;

bool cmp(node a,node b){
    return (a.x<b.x)||(a.x==b.x&&a.tp<b.tp);
}

void insert(int BIT,int tp,int x,int y,int y2){
    info[BIT].tp=tp;
    info[BIT].x = x;
    info[BIT].y = y;
    info[BIT].y2=y2;
}

int lowbit(int k){return k&(-k);}

void add(int k,int delta){
    while(k<=Maxn){
        sum[k]+=delta;
        k+=lowbit(k);
    }
}

int query(int k){
    int s = 0;
    while(k){
        s+=sum[k];
        k-=lowbit(k);
    }
    return s;
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int tot=0,all=0;
        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){//Êú 1 
                if(y1>y2) swap(y1,y2);
                insert(++tot,1,x1,y1,y2);
                a[++all]=y1;
                a[++all]=y2; 
            } else {//ºá 0 
                if(x1>x2) swap(x1,x2);
                insert(++tot,0,x1,y1,1); 
                insert(++tot,0,x2+1,y2,-1);
                a[++all]=y1;
            }
        }
        sort(a+1,a+1+all);
        int cnt = 0;
        mp.clear();
        for(int i=1;i<=all;i++)
            if(!mp[a[i]]) mp[a[i]]=++cnt;
        Maxn = cnt + 1;
        memset(sum,0,sizeof(sum));
        sort(info+1,info+1+tot,cmp);
        LL ans = 0;
        
        for(int i=1;i<=tot;i++){
            if(info[i].tp==0){
                int tp = mp[info[i].y];
                add(tp,info[i].y2);
            } else {
                int l = mp[info[i].y],r=mp[info[i].y2];
                ans += query(r) - query(l-1);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
} 
