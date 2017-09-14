#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        set<int> S;
        for(int i=1;i<=n+m;i++){
            int x;scanf("%d",&x);
            S.insert(x);
        }
        set<int>::iterator it=S.begin();
        set<int>::iterator it1=S.end();
        for(;it!=it1;it++){
            if(it!=S.begin()) printf(" ");
            printf("%d",*it);
        }
        puts("");
        S.clear();
    }
    return 0;
}
