#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        LL ans=0,a,b;
        while(n--){
            cin>>a>>b;
            ans+=a*b;
        }
        cout<<ans<<endl;
    }
    return 0;
}
