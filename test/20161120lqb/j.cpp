#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int htable[10007],f,r;
int next[444444];
int Q[444444][9];
int zeros[444444];
int vis[444444];
int purpose[9];
int pre[444444];
int hash(int pos){
    int num = 0;
    for(int i = 0; i < 9; i++){
        num = num*10+Q[pos][i];
        num%=10007;
    }
    return num;
}

bool insert(int pos){
    int num = hash(pos);
    for(int n = htable[num]; n!=-1; n=next[n]){
        if(memcmp(Q[n], Q[pos], sizeof(int)*9) == 0)
            return false;     
    }
    next[pos] = htable[num];
    htable[num] = pos;
    return true;
}
int bfs(){
    pre[0] = -1;
    while(f < r){
        int *cur = Q[f++];
        if(memcmp(cur, purpose, sizeof(int)*9) == 0)
            return f-1;
        int zx = zeros[f-1]/3;
        int zy = zeros[f-1]%3;

        for(int i = 0; i < 4; i++){
            int nowx = zx+dx[i];
            int nowy = zy+dy[i];
            if(nowx < 0 || nowx >=3 || nowy < 0 || nowy >= 3)
                continue;
            int (*next)[3] = (int (*)[3])Q[r++];
            memcpy((int *)next, cur, sizeof(int)*9);
            next[zx][zy] = next[nowx][nowy];
            next[nowx][nowy] = 0;
            zeros[r-1] = nowx*3+nowy;
            pre[r-1] = f-1;
            if(!insert(r-1))
                r--;
        }
    }
    return -1;
}
int main(){
    memset(htable, -1, sizeof(htable));
    for(int i = 0; i < 9; i++){
        char ch;
        ch=getchar();
        if(ch == '.') {
            Q[r][i] = 0;
            zeros[r] = i;
        }
        else
            Q[r][i] = ch-'0';
    }
    r++;
    for(int i = 0; i < 9; i++){
        char ch;
        cin >> ch;
        if(ch == '.')
            purpose[i] = 0;
        else
            purpose[i] = ch-'0';
    }
    int tot = 0;
    for(int p = bfs(); p!=-1; p=pre[p])
        tot++;
    cout << tot - 1 << endl;
}
