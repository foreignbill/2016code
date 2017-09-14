#include <bits/stdc++.h>
using namespace std; 
int main(){
    char st[1005];
    int r,len;
    while(scanf("%s",st)&&st[0]!='0'){
        r=0;
        len=strlen(st);
        for(int i=0;i<len;i++)
           r+=st[i]-'0';
        printf("%d\n",(r-1)%9+1);
    }
    return 0;
}
