#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n,x;
	while(cin>>n){
	    int ones = 0;
	    int twos = 0;
	    int not_threes = 0;
	
	    int i,t;
	    cin>>t;
	    for(i=1; i<n; i++){	
			cin>>x;
	        t^=x;
	    }
	   cout<<t<<endl;
	}
    return 0;
}
