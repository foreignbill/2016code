#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

#define LL long long  

using namespace std;
map<int,int> mp;
void print(){
	mp.clear();
	int num=1,key=0;
	while(num<=1000000000){
		mp[num]=key;
		num*=2;
		key=key*2+1;
	}
}

int main(){
	int T;
	print();
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		int t=1;
		while(t<=n) t*=2; t=t/2;
		//cout<<mp[2]<<" "<<mp[4]<<endl;
		int ans=0;
		while(n>1){
			if(n>=t){
				n-=t;
				ans+=(mp[t]);
				//cout<<t<<" "<<mp[t]<<endl;
				t/=2;
			}
			else{
				t/=2;
			}
			if(t==0||t==1) break;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
