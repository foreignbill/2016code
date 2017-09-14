/**************************************************************
    Problem: 1003
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:48 ms
    Memory:964 kb
****************************************************************/
 
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int maxm = maxn * maxn;
struct pnode
{
    int d,w;
    pnode *next;
    pnode(){}
    pnode(int d,int w,pnode *next):d(d),w(w),next(next){}
}*first[maxn],__[maxm],*tot = __;
bool flag[maxn][maxn],done[maxn];
int dis[maxn],t[maxn],sum[maxn],f[maxn];
int n,m,k,e,d;
 
void readdata(){
    memset(flag,true,sizeof(flag));
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for(int i = 1;i <= e;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        first[x] = new(tot++)pnode(y,z,first[x]);
        first[y] = new(tot++)pnode(x,z,first[y]);
    }
    scanf("%d",&d);
    for(int i = 1;i <= d;i++){
        int p,a,b;
        scanf("%d%d%d",&p,&a,&b);
        for(int j = a;j <= b;j++)flag[p][j] = false;
    }
}
 
int cost(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    memset(done,false,sizeof(done));
    typedef pair<int,int>pii;
    priority_queue<pii,vector<pii>,greater<pii> >q;
    for(int i = 1;i <= m;i++){
        for(int j = s;j <= t;j++){
            if(!flag[i][j]){
                done[i] = true;
                break;
            }
        }
    }
    dis[1] = 0;
    q.push(make_pair(dis[1],1));
    while(!q.empty()){
        pii u = q.top();q.pop();
        if(done[u.second])continue;
        int k = u.second;
        for(pnode *p = first[k];p != NULL;p = p -> next){
            if(done[p->d])continue;
            if(dis[k] + p -> w < dis[p->d]){
                dis[p->d] = dis[k] + p -> w;
                q.push(make_pair(dis[p->d],p->d));
            }
        }
    }
    if(dis[m] == inf)return dis[m];
    else return dis[m] * (t - s + 1);
}
 
void solve(){
    for(int i = 1;i <= n;i++){
         f[i] = cost(1,i);
         for(int j = 2;j < i;j++){
             f[i] = min(f[i],f[j] + cost(j + 1,i) + k);
         }
    }
    printf("%d",f[n]);
}
 
int main(){
    readdata();
    solve();
    return 0;
}
