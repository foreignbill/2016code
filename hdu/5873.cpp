#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[1000000],tmp[1000000];

int main(){
    int T,n;
    while(scanf("%d",&T)!=EOF){
        while(T--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++) scanf("%d",&num[i]);
            sort(num+1,num+1+n);
            bool pan=true;
            
            int sum=0;
            for(int i=1;i<=n;i++) sum+=num[i];
            if(sum!=(n-1)*n) pan=false;
            
            int delta=2*(n-1)-num[n];
            if(delta<0) pan=false;
            num[n]=0;
            
            for(int i=n-1;i>=1;i--){
                num[i]-=delta;
                delta=2*(i-1)-num[i];
                if(delta<0) pan=false;
                num[i]=0;
            }
            
            if(delta!=0) pan=false;
            if(pan) puts("T");
            if(!pan)puts("F");
        }
    }
    
    return 0;
} 
