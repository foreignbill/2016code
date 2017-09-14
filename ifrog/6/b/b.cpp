#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 55
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
int dp[20][2];
//dp[i][0],表示不存在不吉利数字
//dp[i][1],表示存在不吉利数字
void Init(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=15;i++){
        dp[i][0]=dp[i-1][0]*9;  //在最高位加上除了p之外的9个数字
        dp[i][1]=dp[i-1][1]*10 + 1 + dp[i-1][0];  //在已经有不吉利数字最高位加任意数字，或者在无吉利数字前加p
    }
}

int slove(int n,int p){
    int len=0,bit[20];
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    bit[len+1]=0;
    int ans=0;
    bool flag=false;
    for(int i=len;i;i--){
        ans+=dp[i-1][1]*bit[i];
        if(flag)   //高位已经出现p，后面的就随意
            ans+=dp[i-1][0]*bit[i];
        if(!flag&&bit[i]>p)  //高位可能出现p的情况
            ans+=dp[i-1][0];
        if(bit[i]==p)  //高位已经出现p
            flag=true;
    }
    return ans;
}

int main(){
	freopen("input.txt","r",stdin); 
    int T,l,r,p;
    Init();
    cin>>T;
    while(T--){
		scanf("%d%d%d",&l,&r,&p);
        int ans = slove(r+1,p) - slove(l,p);
        printf("%d\n",ans);
    }
    return 0;
}
