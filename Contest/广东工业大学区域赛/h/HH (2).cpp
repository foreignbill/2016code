#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

unordered_map<int,int> mp;
int ans[3];
int main(){
	int T,n,a;
	T=read();
	while(T--){
		mp.clear();
		n=read();
		for(int i=1;i<=n;i++){
			a=read();
			mp[a]++;
		}
		ans[0]=0;
		for(unordered_map<int,int>::iterator its = mp.begin();its!=mp.end();its++){
			if(ans[0]==2) break;
			if(its->second>1) continue;
			ans[++ans[0]]=its->first;
		}
		if(ans[1]>ans[2]) printf("%d %d\n",ans[2],ans[1]);
		else printf("%d %d\n",ans[1],ans[2]);
	}
	return 0;
}
