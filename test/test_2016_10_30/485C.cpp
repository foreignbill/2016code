#include <bits/stdc++.h> 

using namespace std;

int main(){
    long long a, b;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b;
        for(long long i=1; (a|i) <= b; i<<=1)
            a |= i;
        cout<<a<<endl; 
    }
    return 0; 
}
