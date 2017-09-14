#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,id;
}a[1111];
int b[1111];
bool comp(node x,node y){
    return x.id<y.id;
}
int main(){
    int T;
    while(cin>>T){
        while(T--){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=-1;
            
            for(int i=1;i<=n;i++){
                scanf("%d",&b[i]);
                for(int j=1;j<=n;j++)
                    if(a[j].x==b[i]&&a[j].id==-1){
                        a[j].id=i;
                        break;
                    }
            }
            
            for(int i=1;i<=m;i++){
                int l,r;
                scanf("%d%d",&l,&r);
                sort(a+l,a+r+1,comp);
            }
            
            bool flag=1;
            for(int i=1;i<=n;i++){
                if(a[i].x!=b[i]) flag=0;
            }
            if(flag) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}
