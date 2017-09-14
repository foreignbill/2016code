#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int col[10005];// -1 Good 1 Bad 
int du[10005];
vector<int> e[10005];
queue <int> Q;
bool v[10005];

int main(){
    int n,m,x,y;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
        for(int i=1;i<=n;i++) e[i].clear();
        memset(col,0,sizeof(col));
        while(!Q.empty()) Q.pop();
        memset(v,0,sizeof(v));
        memset(du,0,sizeof(du));//originate
        
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
            du[u]++;
            du[v]++;
        }
        
        for(int i=1;i<=x;i++){//good
            int id;
            scanf("%d",&id);
            col[id]=-1;
            v[id]=1;
            Q.push(id);
        }
        
        for(int i=1;i<=y;i++){//bad
            int id;
            scanf("%d",&id);
            col[id]=1;
            v[id]=1;
            Q.push(id);
        }
        
        bool ok=true;
        
        for(int i=1;i<=n;i++)
            if(du[i]==0&&v[i]==0){
                ok=false;
                break;
            }
        
        if(!ok){
            puts("NO");
            continue;
        }
        
        while(!Q.empty()&&ok){
            int now=Q.front();Q.pop();
            for(int i=0;i<e[now].size();i++){
                int ep=e[now][i];
                if(v[ep]){
                    if(col[ep]+col[now]!=0){
                        ok=false;
                        break;
                    }
                    continue;
                }
                col[ep]=-col[now];
                v[ep]=true;
                Q.push(ep);
            }
        }
        if(!ok) puts("NO");
        else{
            for(int i=1;i<=n;i++)
                if(!v[i]){
                    while(!Q.empty()) Q.pop();
                    Q.push(i);
                    col[i]=1;
                    v[i]=true;
                    while(!Q.empty()&&ok){
                        int now=Q.front();Q.pop();
                        for(int i=0;i<e[now].size();i++){
                            int ep=e[now][i];
                            if(v[ep]){
                                if(col[ep]+col[now]!=0){
                                    ok=false;
                                    break;
                                }
                                continue;
                            }
                            col[ep]=-col[now];
                            v[ep]=true;
                            Q.push(ep);
                        }
                    }
                    if(!ok){
                        break;
                    }
                }
            puts(ok?"YES":"NO");
        }
    }
    
    return 0;
} 
