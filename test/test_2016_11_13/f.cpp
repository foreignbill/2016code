#include <bits/stdc++.h>
using namespace std;
int T,n,m,s,u,v,ans;
vector<int> e[1111];
int g[111][111];
int data[110];
int dfs(int id,int size){
    if(size==s){//找到了一个S个点的团。 
        ans++;
        return 0;
    }
    for(int i=0;i<e[id].size();i++){//取与id相连的点，ep 
        int ep=e[id][i];
        bool flag=true;
        for(int j=1;j<=size;j++){ 
            if(!g[ep][data[j]]){//如果data里前面选中的点跟ep不相连，这个ep不合法。 
                flag=false;
                break;
            }
        }
        if(flag){//ep这个点合法，继续dfs(ep,size+1) 
            size++;
            data[size]=ep;
            dfs(ep,size);
            data[size]=0;
            size--;
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(g,0,sizeof(g));
        scanf("%d%d%d",&n,&m,&s);
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);//边有序化 
            e[u].push_back(v);//单向边 
            g[u][v]=g[v][u]=1;
        }
        ans=0;
        for(int i=1; i<=n; i++){
            int size=1;
            data[1]=i;
            dfs(i,1);//dfs(点号,选中的点的个数); 
        }
        printf("%d\n",ans);
    }
    return 0;
}
