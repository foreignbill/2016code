#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int connect[2000],x,y,n,k;
bool link[560][560],v[2200];

bool find(int u){
    int i;
    for(i=1;i<=n;i++){
        if ((link[u][i])&&(!v[i])){
           v[i]=true;
           if((connect[i]==0)||find(connect[i])){
                connect[i]=u;
                return true;                
            }
        }
    }
    return false;
}

int main(){
    memset(link,sizeof(link),0);
    scanf("%d%d",&n,&k);
    
    for (int i=1;i<=k;i++) {
        scanf("%d%d",&x,&y);
        link[x][y]=true;
    }
    
    int ans=0;
    
    for(int i=1;i<=n;i++){
        memset(v,false,sizeof(v));
        if (find(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}