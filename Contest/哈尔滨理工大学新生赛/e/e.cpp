#include <cstdio>
#include <cstring>
#include <set>
#include <iostream> 
using namespace std;
const int BIT[] = {1,2,4,5};
struct node{
	int a[10];
};
node Q[500000],purpose,now,NEW;

int fac[10],vis[1111111];
void init_fac(){
	fac[0]=1;
	for(int i=1;i<=9;i++) fac[i]=fac[i-1]*i;
} 

void init(){
	for(int i=1;i<=9;i++) purpose.a[i]=i;
	purpose.a[0] = 0;
}

bool insert(int v){
	if(vis[v]) return 0;
	else return vis[v]=1;
}

node swap(int tp){
	node tmp;
	memcpy(tmp.a,now.a,sizeof(tmp.a));
	int temp;
	temp = tmp.a[tp];
	tmp.a[tp] = tmp.a[tp+3];
	tmp.a[tp+3] = tmp.a[tp+4];
	tmp.a[tp+4] = tmp.a[tp+1];
	tmp.a[tp+1] = temp;
	return tmp; 
}

bool check(){
	for(int i=0;i<=9;i++)
		if(NEW.a[i]!=purpose.a[i]) return 0;
	return 1;
}

int main(){
    ios::sync_with_stdio(false);
	init_fac();
	while(~scanf("%d%d%d%d%d%d%d%d%d",&Q[1].a[1],&Q[1].a[2],&Q[1].a[3],&Q[1].a[4],&Q[1].a[5],&Q[1].a[6],&Q[1].a[7],&Q[1].a[8],&Q[1].a[9])){
		memset(vis,0,sizeof(vis));
		int f=1,r=1,ans=0;
		init();
		bool pan=true;
		for(int i=0;i<=9;i++)
			if(Q[f].a[i]!=purpose.a[i]){
				pan=false;
				break;
		}
		if(pan){
			puts("0");
			continue;
		}
		while(f<=r&&ans==0){
			memcpy(now.a,Q[f].a,sizeof(now.a));
			for(int i=0;i<4;i++){
				int tp = BIT[i];
				NEW = swap(tp);	
				memcpy(Q[r+1].a,NEW.a,sizeof(Q[r+1].a));
				Q[r+1].a[0]=Q[f].a[0]+1; 	
				NEW.a[0]=0;
				if(memcmp(purpose.a,NEW.a,sizeof(NEW.a))==0){
					ans = Q[r+1].a[0];
					break; 
				}
				int code = 0;
				for(int i=1;i<=9;i++){
			        int cnt=0;
			        for(int j=i+1;j<=9;++j) if(Q[r+1].a[j]<Q[r+1].a[i]) cnt++;  
			        code+=fac[9-i]*cnt;
    			}
				if(insert(code)) r++;
			}
			f++;
		}
		printf("%d\n",ans);
	}	
	return 0;
}
