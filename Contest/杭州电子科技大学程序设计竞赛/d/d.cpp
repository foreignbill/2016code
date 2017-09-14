#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string op[4]={"Fire","Ice","Dog","Evolved"};

int n,m;
bool flag;
map<string,int> mp;

bool dfs(int harm,int left,int buff){
	if(harm>=m){
		flag=1;
		return 0;
	}
	for(int i=0;i<=3;i++){
		if(mp[op[i]]){
			if(i==2&&left>=2){
				mp[op[i]]--;
				dfs(harm,left-2,buff+1);
				mp[op[i]]++;
			}
			if(i==3&&left>=4){
				mp[op[i]]--;
				dfs(harm,left-4,buff+2);
				mp[op[i]]++;
			}
			if(i==0&&left>=4){
				mp[op[i]]--;
				dfs(harm+buff+6,left-4,buff);
				mp[op[i]]++;
			}
			if(i==1&&left>=2){
				mp[op[i]]--;
				dfs(harm+buff+3,left-2,buff);
				mp[op[i]]++;
			}
		}
	}
}

int main(){
	mp.clear();
	int T;
	string st;
	cin>>T;
	while(T--){
		mp.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			cin>>st;
			mp[st]++;
		}
		flag=0;
		dfs(0,10,0);
		if(flag){
			puts("Yes");
		}
		else{
			puts("No");
		}
	} 
	
	return 0;
} 
