#include <iostream>
using namespace std;
int a[500],rounds,t;
int check(int n){
    for(int i=0;i<n-1;i++)
        if(a[i]!=a[i+1]) return 1;
    return 0;
}
int main(){
    int n,ans=0;
    while(cin>>n&&n){
        rounds=0;
        for(int i=0;i<n;i++) cin>>a[i];
        while(check(n)){
            rounds++;
            t=a[n-1]/2;
            for(int i=n-1;i>0;i--){
                a[i]=a[i]/2+a[i-1]/2;
                if(a[i]%2) a[i]++,ans++;
            }
            a[0]=a[0]/2+t;
            if(a[0]%2) a[0]++,ans++;
        }
        cout<<ans<<endl;
    }
}
