#include <bits/stdc++.h> 
using namespace std;   
int result[24]={0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229}; 
int main() 
{ 
    int n; 
    cin>>n;
    while(n!=0)
    {
        cout<<n<<" "<<result[n-1]<<endl;
        cin>>n;
    }
    return 0;
}
