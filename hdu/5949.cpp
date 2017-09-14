#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    char st[111];
    scanf("%d\n",&T);
    while(T--){
        gets(st);
        int len=strlen(st);
        int ans=0;
        for(int i=0;i<len;i++){
            if(st[i]=='H') ans++;
            if(st[i]=='O') ans+=16;
            if(st[i]=='C') ans+=12;
        }
        printf("%d\n",ans);
    }
    return 0;
} 
