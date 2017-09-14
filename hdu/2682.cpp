#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[605];
struct node{
    int x,y,w;
}e[180005];

bool comp(node a,node b){
    return a.w<b.w;
}

int prime[2000005],temp,binc[605];

int Find(int k){
    if(binc[k]==k)    return k;
    binc[k]=Find(binc[k]);
    return binc[k];
}

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x;  
}

int main(){
    
    memset(prime,-1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<=2000000;i++)
        if(prime[i]==-1){
            for(temp=2*i;temp<=2000000;temp+=i)    prime[temp]=0;
        }
    
    T=read();
    while(T--){
        n=read();
        int top=0;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(prime[a[i]] || prime [a[j]] || prime[a[i]+a[j]]){
                    e[++top].w = min( min(a[i] , a[j]) , abs(a[i] - a[j]) );
                    e[top].x=i;
                    e[top].y=j;
                }
        sort(e+1,e+1+top,comp);
        
        int k=0,ans=0,h1,h2;
        for(int i=1;i<=n;i++)    binc[i]=i;
        for(int i=1;i<=top;i++){
            if(k==n-1) break;
            h1=Find(e[i].x);h2=Find(e[i].y);
            if(h1==h2) continue;
            ans+=e[i].w;
            binc[h1]=h2;
            k++;
        }
        printf("%d\n",k<n-1?-1:ans);
    }
    
}
