#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 510;
int col[N], g[N][N];

//0为白色，1为黑色 
bool bfs(int s, int n) {
    queue<int> p;
    p.push(s);
    col[s] = 1;
    while(!p.empty()) {
        int from = p.front();
        p.pop();
        for(int i = 1; i <= n; i++) {
            if(g[from][i] && col[i] == -1) {
                p.push(i);
                col[i] = !col[from];//染成不同的颜色 
            }
            if(g[from][i] && col[from] == col[i])//颜色有相同，则不是二分图 
                return false;
        }
    }
    return true;     
}

int main() {
    int n, m, a, b, i;
    memset(col, -1, sizeof(col));
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    bool flag = false;
    for(i = 1; i <= n; i++)
        if(col[i] == -1 && !bfs(i, n)) {//遍历各个连通分支 
            flag = true;
            break;  
        }
    if(flag)
        cout << "NO" <<endl;    
    else
        cout << "YES" <<endl;
    return 0;
}
