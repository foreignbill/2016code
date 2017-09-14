#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	long long T,n;
	cin>>T;
	{
		while(cin>>n){
			long long ans = 0;
			long long t = 1 , sum = 0;
			while(sum<n){
				ans++;
				sum+=t;
				t*=3;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
