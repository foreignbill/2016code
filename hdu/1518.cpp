#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int T,n,sum,len;
int info[25];
bool v[25],flag;

int dfs(int id,int completed,int length){
    if(completed==4)return 1;
    for(int i=id;i<=n;i++){
        if(!v[i]){
            if(length-info[i]==0){
                v[i]=1;
                if(dfs(1,completed+1,len)) return 1; 
                v[i]=0;
            }
            else if(length-info[i]>0){
                v[i]=1;
                if(dfs(i+1,completed,length-info[i])) return 1;
                v[i]=0;
            }
        }
    }
    return 0;
}

bool cmp(int a,int b){
    return a>b;
}

int main(){
    cin>>T;
    while(T--){
        sum = 0;
        scanf("%d",&n);    
        for(int i=1;i<=n;i++){
            scanf("%d",info + i);
            sum+=info[i];
        }
        sort(info+1,info+1+n,cmp);
        if(sum%4||n<4){
            puts("no");
            continue;
        }
        len = sum/4;
        memset(v,0,sizeof(v));
        if(dfs(0,0,len))    puts("yes");
            else     puts("no");
    }
    return 0;
} 
