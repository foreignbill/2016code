#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int num[1111];
int f[1111];
int cost[1111];
int value[1111];

int main(){
	int T,L,times,n;
	cin>>T;
	while(T--){
		scanf("%d%d%d",&L,&times,&n);
		for(int i=1;i<=times;i++) scanf("%d",num+i);
		
		memset(f,0,sizeof(f));
		
		for(int i=1;i<=n;i++) scanf("%d%d",cost+i,value+i);
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<=L;j++)
				if(j-cost[i]>=0){
					f[j] = max(f[j] , f[j-cost[i]]+value[i]);
				}
		}
		
		int ans=0;
		
		sort(num+1,num+1+times);
		
		for(int i=1;i<=times;i++){
			ans+=f[num[i]-num[i-1]];
		}
		
		if(num[times]<L) ans += f[L-num[times]];
		
		printf("%d\n",ans);
	}
	return 0;
}
