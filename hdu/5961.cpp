#include <bits/stdc++.h>
using namespace std;

int n;

struct node{
    vector<int> e[2020];
    
    int add(int u,int v){
        e[u].push_back(v);
    }
    
    int init(int _n){
        for(int i=1;i<=_n;i++) e[i].clear();
    }
    
    bool bfs(int s){
        int d[2020];
        memset(d,0,sizeof d);
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int now=Q.front();
            Q.pop();
            for(int i=0;i<e[now].size();i++){
                int id=e[now][i];
                if(d[id]) continue;
                else{
                    d[id]=d[now]+1;
                    Q.push(id);
                    if(d[id]>=2) return false;
                }
            }
        }
        return true;
    }
    
    bool BFS(){
        for(int i=1;i<=n;i++){
            if(bfs(i)==false) return false;
        }
        return true;
    }
    
}P,Q;

int main(){
    int T;
    scanf("%d\n",&T);
    while(T--){
        scanf("%d\n",&n);
        P.init(n);Q.init(n);
        char ch;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ch=getchar();
                if(ch=='-') continue;
                if(ch=='P'){
                    P.add(i,j);
                    continue;
                } 
                if(ch=='Q'){
                    Q.add(i,j);
                    continue;
                }
            }
            ch=getchar();
        }
        
        bool ok=true;
        ok=ok&P.BFS();
        ok=ok&Q.BFS();
        puts(ok?"T":"N");
    }
    
    return 0;
} 
