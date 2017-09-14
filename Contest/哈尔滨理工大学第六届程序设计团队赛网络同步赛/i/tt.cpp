#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

struct node{
	int type,x,fa,times;
}info[55555];

bool succeed[55555];

map<int,int> mp;

int main(){
	freopen("input.txt","r",stdin);
	int T,n,m;
	cin>>T;
	while(T--){
		for(int i=0;i<=55554;i++){
			info[i].type=0;
			info[i].x=0;
			info[i].times=0;
			info[i].fa=0;
		}
		mp.clear();
		memset(succeed,1,sizeof(succeed));
		scanf("%d%d",&n,&m);
		
		for(int i=1;i<=m;i++){
			scanf("%d%d",&info[i].type,&info[i].x);
			if(info[i].type==1){
				if(mp[info[i].x]==1) succeed[i]=0;
				mp[info[i].x]=1;
			}
			if(info[i].type==2){
				if(mp[info[i].x]==0) succeed[i]=0;
				mp[info[i].x]=0;
			}
			if(info[i].type==3){
				if(info[info[i].x].type==1&&succeed[info[i].x]==1){
					mp[info[info[i].x].x]=0;
				}
				if(info[info[i].x].type==2&&succeed[info[i].x]==1){
					mp[info[info[i].x].x]=1;
				}
				if(info[info[i].x].type==3){
					int t=info[i].x;
					while(info[t].type==3){
						if(succeed[info[t].x]==0) break;
						t=info[i].x;
						succeed[info[t].x]=0;
					}
					if(info[t].type==1&&succeed[t]==1){
						mp[info[t].x]=0;
					}
					if(info[t].type==2&&succeed[t]==1){
						mp[info[t].x]=1;
					}
				}
			}
		} 

		map<int,int>::iterator its=mp.begin();
		int ans=0;
		for(;its!=mp.end();its++){
			ans+=its->second; 
		}
		its=mp.begin(); 
		int flag=0;
		printf("%d\n",ans); 
		for(;its!=mp.end();its++){
			if(its->second==0) continue;
			if(flag) printf(" "); 
			printf("%d",its->first);
			flag=1;
		}
		puts("");
	}
	return 0;
}
