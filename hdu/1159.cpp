#include <bits/stdc++.h>
using namespace std;
char st1[1111],st2[1111];
int f[1111][1111];
int main(){
    while(scanf("%s%s",st1+1,st2+1)!=EOF){
        memset(f,0,sizeof f);
        int len1=strlen(st1+1),len2=strlen(st2+1);
        
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++){
                if(st1[i]==st2[j]){
                    f[i][j]=f[i-1][j-1]+1;
                    continue;
                }
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
         printf("%d\n",f[len1][len2]);
    }
    return 0;
}
