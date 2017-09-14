#include <bits/stdc++.h>
using namespace std;
int d[255],dist[255],a,b;

int bfs(int s,int t){
    int now;
    queue<int> Q;
    Q.push(s);//»Î∂” 
    dist[s]=1;
    bool flag=false;
    while(!Q.empty()){
        now=Q.front();Q.pop();
        if(now==t) {flag=true;break;}
        int next=now+d[now];
        
        if(1<=next&&next<=b&&!dist[next]){
            Q.push(next);
            dist[next]=dist[now]+1;
        }
        next=now-d[now];
        if(1<=next&&next<=b&&!dist[next]){
            Q.push(next);
            dist[next]=dist[now]+1;
        }
    }
    return dist[t];
}

int main(){
    int N;
    while(scanf("%d",&N),N){
        scanf("%d%d",&a,&b);
        for(int i=1;i<=N;i++) scanf("%d",&d[i]);
        memset(dist,0,sizeof(dist));
        int ans=bfs(a,b); 
        if(ans==0) puts("-1");
        else printf("%d\n",ans-1);
    }
    
    return 0;
} 
