#include <cstdio>
#include <iostream>
#define ULL unsigned long long
using namespace std;
int main(){
	ULL mx=0,T,l,r;
	while(cin>>T){
		while(T--){
			cin>>l>>r;
	        for(long long i=1; (l|i) <= r; i<<=1)
            	l |= i;
            cout << (l|r) << endl; 
		}
	}
	return 0;
}
