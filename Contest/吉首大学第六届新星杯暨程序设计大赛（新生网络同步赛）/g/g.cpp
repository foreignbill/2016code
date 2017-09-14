#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int bit[64];
int base[64]={};
int n,x;
int main(){
	while(cin>>n){
		int top=0;
		int A=0,B=0;
		for(int i=1;i<=n;i++){
			cin>>x;
		    A =A ^ x & ~B;
		    B =B ^ x & ~A;
		}
		cout<<B<<endl;
	}
	return 0;
} 
