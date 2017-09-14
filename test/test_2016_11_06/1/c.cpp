#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[110];
int pos[4];
int main(){
    freopen("in.txt","r",stdin);
    while(gets(str) != NULL){
        int cnt = 0,flag = 1;
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            if(str[i] == '.') pos[cnt++] = i;
            else if(str[i] < '0' || str[i] > '9') flag = 0;
        }
        if(pos[0] >= 4 || pos[0] == 0 || cnt != 3) flag = 0;
        for(int i = 1; i <= 2; i++){
            int temp = pos[i]-pos[i-1];
            if(temp > 4 || temp == 0) { flag = 0; break;}
        }
        int c = 0;
        for(int i = 0; i < len; i++)
        	if(str[i]!= '.') c = c*10+str[i]-'0';
        		else if(c > 255) flag  = 0;
        		else c = 0;
        if(c  > 255) flag = 0;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
