#include <bits/stdc++.h>
using namespace std;
struct node{
    int v,c;
    node(int _v=0,int _c=0):v(_v),c(_c){}
};
vector<node> e[444444];
void add(int u,int v,int w){
    e[u].push_back(node(v,w));
}

int query(int id){
    int ans=0;
    for(int i=0;i<e[id].size();i++){
        ans+=e[id][i].c;
    }
    return ans%2;
}

void change(int x,int y,int w){
    for(int i=0;i<e[x].size();i++){
        if(e[x][i].v==y){
            e[x][i].c=w;
            return;
        }
    }
}

int main(){
    int T,n,m,x,y,w,t;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&t,&x);
            if(t!=0) scanf("%d%d",&y,&w);
            if(t==0) puts(query(x)?"Girls win!":"Boys win!");
            else change(x,y,w),change(y,x,w);
        }
    }
    return 0;
} 
