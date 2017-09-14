#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
int T, N, M;
char buf[MAXN];
int dot, pos;
inline bool finish() {
    return (dot == -1 || pos == -1);
} 

int main() {
    while(~scanf("%d %d", &N, &T)) {
        scanf("%s", buf);
        bool overflow = false;
        dot = -1, pos = -1;
        for(int i = 0; buf[i]; i++) {
            if(buf[i] == '.') {
                dot = i;
                break;
            }
        }
        for(int i = dot + 1; buf[i]; i++) {
            if(buf[i] >= '5') {
                pos = i;
                buf[i + 1] = '\0';
                break;
            }
        }
        while(T --) {
            if(finish()) break;
            if(buf[dot + 1] >= '5') {
                buf[dot + 1] = buf[dot] = '\0';
                int j = dot - 1;
                while(j >= 0 && buf[j] == '9') {
                    buf[j] = '0';
                    j --;
                }
                if(j < 0 && buf[j + 1] == '0') overflow = true;
                else buf[j] ++;
                break;
            }
            buf[pos] = '\0';
            buf[pos - 1] ++;
            if(buf[pos - 1] < '5') pos = -1;
            else pos --;
        }
        if(overflow) printf("1");
        printf("%s\n", buf);
    }
    return 0;
}
