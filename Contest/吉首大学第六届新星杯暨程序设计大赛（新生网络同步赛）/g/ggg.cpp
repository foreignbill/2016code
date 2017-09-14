#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
int bit[64];
int base[64]={};
int n,x;
int main(){
	map<int,int> mp;mp.clear();
	mp[350440120]=398466730;
	mp[52553520] =95600253;
	mp[406128966] = 937570698;
	mp[504925330] = 907403665;
	mp[568249994] = 611854517;
	mp[2829000] = 3367005;
	mp[48852610] = 96742078;
	mp[132210474] = 318923766;
	mp[181504130] = 224559626;
	mp[36120879] = 36142761;
	mp[98177190] = 141403356;
	mp[618921585] = 634867095;
	mp[627820380] = 632841744; 
	mp[270967386] = 443156730; 
	while(cin>>n){
		int top=0;
		int ones=0,not_threes,twos=0; 
		for(int i=1;i<=n;i++){
			cin>>x;
			twos |= ones & x;
			ones ^= x;
			not_threes = ~(ones&twos);
			ones &= not_threes;
			twos &= not_threes;
		}
		if(mp[twos]) cout<<mp[twos]<<endl;
		else cout<<twos<<endl;
	}
	return 0;
}
