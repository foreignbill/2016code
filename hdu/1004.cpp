#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d\n",&n),n){
          string str[1001],color;
          int sum[1001];
          int tot=0;
          int i,j;
          for (i=1;i<=n;i++){
               cin>>color; 
               bool flag;
               flag=false;
               for (j=1;j<=tot;j++){
                   if (color==str[j]) {
                   sum[j]++;
                   flag=true;
                   break;
                 }
               }
               if (flag==false){
                   tot++;
                   sum[tot]=1;
                   str[tot]=color;
               }
           }
          int max=0;
          int ans;
          for (i=1;i<=tot;i++)
           if (sum[i]>max) {
             max=sum[i];
             ans=i; 
           }  
           
        cout<<str[ans]<<endl;
      }
      return 0;
} 
