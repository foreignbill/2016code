#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=700+5;
char map[maxn][maxn];
int vis[maxn][maxn];
int n,m;
struct point{
    int x,y;
    point(int x,int y): x(x),y(y) {}
};
int dx[5]={-1,0,1,0};
int dy[5]={0,-1,0,1};
void dfs(vector<point> &v)
{
    vector<point> tmp;
    for(int i=0;i<4;i++)
    {
        tmp.clear();
        for(int j=0;j<v.size();j++) tmp.push_back(v[j]);
        bool ok=true;
        int count=0;
        for(int j=0;j<tmp.size();j++)
        {
            int x=tmp[j].x+dx[i];
            int y=tmp[j].y+dy[i];
            if(vis[x][y]) count++;
            if(x<1||y<1||x>n||y>m||map[x][y]=='#') {ok=false;break;}
        }
        if(tmp.size()==count) ok=false;
        if(ok)
        {
            for(int j=0;j<tmp.size();j++){
                tmp[j].x+=dx[i];
                tmp[j].y+=dy[i];
                vis[tmp[j].x][tmp[j].y]=1;
            }
            dfs(tmp);
        }
    }
}
int main()
{
    int kase=0;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
        memset(vis,0,sizeof(vis));
        vector<point> v;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(map[i][j]=='o') {vis[i][j]=1;v.push_back(point(i,j));}
            }
        }
        dfs(v);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) ans++;
            }
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
