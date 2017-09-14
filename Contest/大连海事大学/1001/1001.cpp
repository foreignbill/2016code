#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
vector<int > e[10005];
bool v[10005];
int  d[10005];//-1 no 0 good 1 bad
int du[10005];
bool good[10005],bad[10005];
queue<int >  Q;

bool bfs(int id){
	bool ok=true;
	
	Q.push()
	
	while(!Q.empty()&&ok){
		int nowid=Q.front();Q.pop();
		for(int i=0;i<e[nowid].size();i++){
			int ep=e[nowid][i];
			if( v[ep] ){
				if(d[nowid] + d[ep] != 1){
					ok=false;
					break;
				}
				continue;
			}
			Q.push(ep);
			v[ep]=1;
			d[ep] = d[nowid] ^ 1;
		}
	}
	
	return ok;
}

int main(){
	int n,m,x,y;
	while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
		for(int i=1;i<=n;i++) e[i].clear();
		while(!Q.empty()) Q.pop();
		memset(du,0,sizeof(du));
		memset(d,-1,sizeof d);
		memset(v, 0,sizeof v);
		memset(good , 0 ,sizeof good);
		memset(bad, 0 ,sizeof bad);
		
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			du[v]++;
			du[u]++;
		}

		if(x!=0){
			int id;
			for(int i=1;i<=x;i++){
				scanf("%d",&id);
				Q.push(id);
				d[id]=0;
				v[id]=1;
				good[id]=1;
			}
		}
		
		if(y!=0){
			int id;
			for(int i=1;i<=x;i++){
				scanf("%d",&id);
				Q.push(id);
				d[id]=1;
				v[id]=1;
				bad[i]=1;
			}
		}

		for(int i=1;i<=n;i++){
			if(du[i]==0){
				if(good[i]){
					d[i]=0;
					v[i]=1; 
				}
				if(bad[i]){
					d[i]=1;
					v[i]=1;
				}
			}
		} 

		int min=INT_MAX,tp=0;
		for(int i=1;i<=n;i++){
			if(d[i]!=-1) continue;
			if(min>du[i]){
				min=du[i];
				tp=i;
			}
		}

		if(tp!=0&&d[tp]==-1){
			Q.push(tp);
			d[tp]=1;
			v[tp]=1;
		}
		
		bool pan=true;
		for(int i=1;i<=n;i++){
			if(d[i]==-1){
				if(!bfs(i)){
					pan=false;
					break;
				}
			}
		} 
		
		puts(pan?"YES":"NO");	
	}
	return 0;
}
