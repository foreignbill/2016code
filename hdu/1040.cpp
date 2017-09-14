#include <iostream>

using namespace std;

int main(){
    int T, n, a[1000], i, j;
    cin>>T;
    while(T--){
        cin>>n;
        for (i = 0; i < n; i++) cin>>a[i];
        for (i = 0; i < n; i++)
            for (j = i+1; j < n; j++) {
                if(a[i] > a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        cout<<a[0];
        for (i = 1; i < n; i++)
            cout<<" "<<a[i];
        cout<<endl;
    }
    return 0;
}
