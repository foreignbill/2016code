/**************************************************************
    Problem: 1103
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:4868 ms
    Memory:15676 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
  
using namespace std;
  
int n,m,a,b,tt=0,r=0;
int fa[250010],num[500010],f1[250010],f2[250010];
int g[250010],e[250010],t[500010],next[500010];
char ch;
 
int lowbit(int x){
    return x & (x ^ (x - 1));
}
 
void add(int x,int d){
    while   (x<=2*n){
        num[x]+=d;
        x+=lowbit(x);
    }
}
  
int ask(int x){
    int query=0;
    while   (x){
        query+=num[x];
        x-=lowbit(x);
    }
    return  query;
}
  
void dfs(int query){
    ++tt;f1[query]=tt;add(tt,1);
    for (int u=g[query];u;u=next[u])
        if  (fa[query]!=t[u]){
            fa[t[u]]=query;
            dfs(t[u]);
        }
    ++tt;f2[query]=tt;add(tt,-1);
}
  
void addedge(int a,int b){
    t[++r]=b;
    if  (g[a])  {next[e[a]]=r;e[a]=r;}
    else    g[a]=e[a]=r;
}
  
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    dfs(1);
    scanf("%d",&m);
    ch=getchar();
    m+=n-1;
    while   (m--){
        scanf("%c%d",&ch,&a);
        if  (ch=='A'){
            scanf("%d\n",&b);
            if  (fa[a]==b)  swap(a,b);
            add(f1[b],-1);
            add(f2[b],1);
        }
        else{
            printf("%d\n",ask(f1[a])-1);
            ch=getchar();
        }
    }
    return  0;
}
