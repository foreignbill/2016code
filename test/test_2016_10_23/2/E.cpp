#include <bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> m;
	int n,id,power;
	while(scanf("%d",&n)==1&&n){
		m.clear();
		m[1000000000]=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&id,&power);
			map<int,int>::iterator it = m.lower_bound(power);
			if(it == m.end()){
				it--;
				printf("%d %d\n",id,it->second);
				m[power]=id;
				continue;
			}
			int t1=it->first;
			int tmp=it->second;
			
			if(it!=m.begin()){
				it--;
				if(power-it->first<=t1-power){
					printf("%d %d\n",id,it->second);
				}
				else printf("%d %d\n",id,tmp);
			}
			else printf("%d %d\n",id,it->second);
			m[power]=id;
		}
	}
	return 0;
} 
