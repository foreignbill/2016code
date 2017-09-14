#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

int reserve(int x){
	int r=0;
	while(x){
		r=r*10+x%10;
		x/=10;
	}
	return r;
}

int main(){
	freopen("output.txt","w",stdout);
	map<int,int> mp;
	mp.clear();
	for(int i=13;i<=1000000;i++){
		if(i==reserve(i)) continue;
		if(isprime(i)&&isprime(reserve(i))){
			mp[i]++;
			mp[reserve(i)]++;
		}
	}
	
	map<int,int>::iterator its=mp.begin();
	int cnt=0;
	for(;its!=mp.end();its++){
		cout<<its->first<<",";
		cnt++;
		if(cnt>1000) break;
	}
	
	return 0;
} 
