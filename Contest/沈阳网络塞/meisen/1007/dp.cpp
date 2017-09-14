#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;

int dig[20],len;
ll dp[20][2][20][2];

ll dfs(int pos,int pre=0,int ln=0,bool inf=1,bool ze=1)//pre 1Ϊ�棬0Ϊż
{
    if(!pos)
    {
        if(pre)return (ln&1)==0;
        else return ln&1;
    }
    if(!inf&&dp[pos][pre][ln][ze]!=-1)return dp[pos][pre][ln][ze];
    int en=inf?dig[pos]:9;ll ans=0;
    F(i,0,en)
    {
        if(i&1)
        {
            if(ze)
            {
                if(i==0)ans+=dfs(pos-1,0,0,inf&&i==en,1);
                else ans+=dfs(pos-1,1,1,inf&&i==en,0);
            }
            else if(pre==0)
            {
                if(ln&1)ans+=dfs(pos-1,1,1,inf&&i==en,ze);
            }else if(pre==1)
            {
                ans+=dfs(pos-1,1,ln+1,inf&&i==en,ze);
            }
        }else
        {
            if(ze)
            {
                if(i==0)ans+=dfs(pos-1,0,0,inf&&i==en,1);
                else ans+=dfs(pos-1,0,1,inf&&i==en,0);
            }
            else if(pre==0)ans+=dfs(pos-1,0,ln+1,inf&&i==en,ze);
            else if(pre==1)
            {
                if((ln&1)==0)ans+=dfs(pos-1,0,1,inf&&i==en,ze);
            }
        }
    }
    if(!inf)dp[pos][pre][ln][ze]=ans;
    return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
    int t,ic=1;ll l,r;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld%lld",&l,&r),l--;
        for(len=0;l;l/=10)dig[++len]=l%10;
        ll tp=dfs(len);
        for(len=0;r;r/=10)dig[++len]=r%10;
        printf("Case #%d: %lld\n",ic++,dfs(len)-tp);
    }
    return 0;
}
