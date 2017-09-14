#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int T,n,m,l1,l2,r1,r2;

double find(int a[],int x){
    if(r1<=l2){
        if(x<=r1-l1+1) return a[l1+x-1];
        else return a[l2+x-1-r1+l1-1];
    }
    else if(r1<=r2){
        if(x<=l2-l1) return a[l1+x-1];
        else if(x>r1-l1+1+r1-l2+1) return a[l2+x-r1+l1-1-1];
        else return a[l2+(x-l2+l1+1)/2-1];
    }
    else{
        swap(r1,r2);
        if(x<=l2-l1) return a[l1+x-1];
        else if(x>r1-l1+1+r1-l2+1) return a[l2+x-r1+l1-1-1];
        else return a[l2+(x-l2+l1+1)/2-1];
    }
}

int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        
        for(int i=1;i<=m;i++){
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            int len = r1-l1+1 + r2-l2+1;
            if(l1>l2){
                int t =l1;l1=l2;l2=t;
                    t =r1;r1=r2;r2=t;
            }
            double mid; 
            if(len&1) mid = find(a,len/2+1);
            else mid = 0.5*find(a,len/2) + 0.5*find(a,len/2+1);
            printf("%.1lf\n",mid);
        }
    } 
    
    return 0;
} 
