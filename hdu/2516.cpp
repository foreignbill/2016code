#include <bits/stdc++.h>
using namespace std;
long long F[100];
int main(){
    F[1]=1;F[2]=2;
    for(int i=3;i<=45;i++) F[i]=F[i-1]+F[i-2];
    long long n;
    while(cin>>n,n){
        bool ok=false;
        for(int i=1;i<=45;i++){
            if(F[i]==n) ok=true;
        }
        puts(ok?"Second win":"First win");
    } 
    
    return 0;
}
