#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=1000011;
struct Node{
       int l,r,root,min,max;
}tree[maxn*5];
int minl[maxn],maxl[maxn],a[maxn],k,len;
void build(int l,int r,int root){   
     tree[root].l=l;
     tree[root].r=r;
     if(l==r){
              tree[root].min=tree[root].max=a[l];
              return;
              }
     int mid=(l+r)>>1;
     build(l,mid,root*2);
     build(mid+1,r,root*2+1);
     tree[root].min=min(tree[root*2].min,tree[root*2+1].min);
     tree[root].max=max(tree[root*2].max,tree[root*2+1].max);
}
bool init(){
     if(scanf("%d",&k)==EOF)return false;
     scanf("%d",&len);
     for(int i=1;i<=k;i++)scanf("%d",&a[i]);
     build(1,k,1);
     return true;
}
void query(int l,int r,int &min,int &max,int root){
     if(tree[root].l==l&&tree[root].r==r){
                                          min=tree[root].min;
                                          max=tree[root].max;
                                          return;
                                          }
     int mid=(tree[root].l+tree[root].r)>>1;
     if(mid>=r)query(l,r,min,max,root*2);
     else if(mid<l)query(l,r,min,max,root*2+1);
          else{
               int max2,min2;
               query(l,mid,min,max,root*2);
               query(mid+1,r,min2,max2,root*2+1);
               min=min<min2?min:min2;
               max=max>max2?max:max2;
               }
}
void work(){
     int ans1,ans2,i;
     for(i=1;i<=k-len+1;i++){
                             query(i,i+len-1,ans2,ans1,1);
                             minl[i]=ans2;
                             maxl[i]=ans1;
                             }
}
void print(){
     int i;
     for(i=1;i<=k-len+1;i++)printf("%d ",minl[i]);
     putchar('/n');
     for(i=1;i<=k-len+1;i++)printf("%d ",maxl[i]);
     putchar('/n');
}
int main(){
    while(init()){
                  work();
                  print();
                  }
    return 0;
}
