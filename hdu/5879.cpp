#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
double ans[200000];
int top=0;
char N[3000000];

int main(){
    double now=0.0,last=0.0;
    for(long long i=1;i<=110292;i++){    
        now+=1.0/(i*i);
        ans[i]=now; 
    }
    
    while(scanf("%s",&N)!=EOF){
        int ll=strlen(N);
        if(ll>=7) puts("1.64493");
        else{
            n=0;
            for(int i=0;i<ll;i++) n=n * 10 + N[i] - '0';
            
            if(n>=110292) puts("1.64493");    
            else printf("%.5f\n",ans[n]);
        }
    }
    return 0;
}
