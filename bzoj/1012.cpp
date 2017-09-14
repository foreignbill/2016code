/**************************************************************
    Problem: 1012
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:996 ms
    Memory:16896 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
  
using namespace std;
 
struct treetype{
       int data,delta,l,r;
};
 
treetype tree[1000000];
 
int insert(int x,int len,int l,int r,int id){
    if(l==r){
        tree[id].data=x;
        return 0;
    }
    int mid=(l+r)>>1;
    if(mid>=len) insert(x,len,l,mid,id*2);
    else insert(x,len,mid+1,r,id*2+1); 
    tree[id].data=max(tree[id*2].data,tree[id*2+1].data);
}
 
int query(int l,int r,int left,int right,int id){
    if(l<=left&&r>=right) return tree[id].data;
    int mid=(left+right)>>1;
    int ans=0;
    if(l<=mid) ans=max(ans,query(l,r,left,mid,id*2)); 
    if(r>mid) ans=max(ans,query(l,r,mid+1,right,id*2+1));
    return ans;
}
 
int main(){
    int m,base,x,t=0,len=0,n;
    char s[200];
    scanf("%d%d",&n,&base);
    for(int cnt=1;cnt<=n;cnt++){
        scanf("%s%d",&s,&x);
        if(s[0]=='A'){
            len++;
            insert((t+x)%base,len,1,n,1);
        }
        else{
            t=query(len-x+1,len,1,n,1);
            printf("%d\n",t); 
        }
    }
    return 0;   
}
