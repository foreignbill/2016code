#include <bits/stdc++.h>

using namespace std;

const int num[]={0,0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14,15,16,17};
              // 0 1 2 3 4 5 6 7 8 91011
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        int top=1; 
        while(T--){
            int n;
            scanf("%d",&n);
            printf("Case #%d: %d\n",top,num[n]);
            top++;
        }
    }
    
    return 0;
} 

