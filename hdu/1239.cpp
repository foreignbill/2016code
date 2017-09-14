#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int prime[2005],num[10001],k;

void printprime(){
   for(int i=2;i<=10000;i++)
       if(num[i]==0){
           for(int t=2*i;t<=10000;t+=i)
               num[t]=1;
           prime[k++]=i;
       }
}

int main(){ 
    int t,m,a,b,ansp,ansq; 
    double ratio,mx;
    memset(num,0,sizeof(num)); 
    num[0]=num[1]=1; 
    k=0;
    printprime();
    while(scanf("%d%d%d",&m,&a,&b)!=EOF,(m||a||b)){
        ratio=a*1.0/b;
        mx=0;
        for(int i=k-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(prime[i]*prime[j]>m||(double)prime[j]/prime[i]<ratio) continue;  
                if(prime[i]*prime[j]>mx){
                    ansp=prime[j];
                    ansq=prime[i];
                    mx=prime[i]*prime[j];
                }
            }
        }
        printf("%d %d\n",ansp,ansq);
    } 
    return 0; 
}
