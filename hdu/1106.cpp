#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 10010
char s[N];
int a[N];

int change(string s){
    int len = s.length();
    int sum = 0;
    for(int i = len - 1, j = 0; i >= 0; --i, ++j)
        sum += (int)(s[i] - '0') * pow(10.0, j);
    return sum;
}

int main(){
    int len, num;
    string ans;
    while(scanf("%s", s) != EOF){
        len = strlen(s);
        num = 0;
        ans = "";
        for(int i = 0; i < len; ++i){
            if(s[i] != '5'){
                ans += s[i];
                if(i == len - 1) 
                    a[num++] = change(ans);
            }
            else if(s[i] == '5' && s[i - 1] != '5' && i != 0) {
                a[num++] = change(ans);
                ans = "";
            }
        }
        sort(a, a + num);
        for(int i = 0; i < num - 1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[num - 1]);
    }
    return 0;
}
