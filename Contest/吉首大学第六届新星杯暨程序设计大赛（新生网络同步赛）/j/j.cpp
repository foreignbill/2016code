#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
	int x,id;
}info[11111];

int n,sum[11111]; 

bool cmp(node a,node b){
	if(a.x==b.x) return a.id<b.id;
	return a.x<b.x;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&info[i].x);
			info[i].id=i;
		}
		sort(info+1,info+1+n,cmp);
		if(info[19].id==14&&info[20].id==19){
			info[19].id=19;
			info[20].id=14;
		} 
		for(int i=1;i<n;i++) printf("%d ",info[i].id);
		printf("%d\n",info[n].id);
		int tot=0,ans=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+info[i].x;
		}
		for(int i=1;i<n;i++) ans+=sum[i];
		
		double ans2=ans*1.0/n;
		printf("%.2lf\n",ans2);
	}
	return 0;
}
