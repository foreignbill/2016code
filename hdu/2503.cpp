#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int e=a*d+b*c,f=b*d;
        printf("%d %d\n",e/gcd(e,f),f/gcd(e,f));
    } 
    
    return 0;
} 
