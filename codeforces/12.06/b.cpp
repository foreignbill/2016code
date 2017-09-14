#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

#define LL long long 

using namespace std;

int n,x;
int a;

map<int,int> mp;

int main(){
	scanf("%d%d",&n,&x);
	mp.clear();
	LL ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(mp[x^a]) ans+=mp[x^a];
		mp[a]++;
	}
	cout<<ans<<endl;
	return 0;
}
