#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string,int> mp;
char st[1000];

int main(){
    mp.clear();
    while(gets(st)){
        if(st[0]=='\0') break;
        int len = strlen(st);
        for(int i=len-1;i>=0;i--){
            mp[st]++;
            st[i]='\0';
        }
    }
    while(gets(st)){
        printf("%d\n",mp[st]);
    }
    return 0;
}
