/**************************************************************
    Problem: 1048
    User: foreignbill
    Language: C++
    Result: Accepted
    Time:236 ms
    Memory:4268 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
 
#define INF 1000000000
 
using namespace std;
 
int a,b,n,h,sum;
int num[15][15];
int f[15][15][15][15][15];
 
int getsum(int x1,int y1,int x2,int y2){
    int ss=0;
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++) ss+=num[i][j];
    return ss * ss; 
}
 
int dp(int x1,int y1,int x2,int y2,int times){
    int & z = f[x1][y1][x2][y2][times];
    if(~z) return z;
    if(times == 1 ){
        int tt = getsum(x1,y1,x2,y2);
        return tt;
    }
    z = INF;
    for(int i=x1;i<x2;i++)
        for(int j=1;j<times;j++)
            z = min( z , dp(x1,y1,i,y2,j) + dp(i + 1,y1,x2,y2,times - j) );
    for(int i=y1;i<y2;i++)
        for(int j=1;j<times;j++)
            z = min( z , dp(x1,y1,x2,i,j) + dp(x1,i + 1,x2,y2,times - j) );
    return z;
}
 
int main(){
    while(scanf("%d%d%d",&a,&b,&n)!=EOF){
        sum=0;
        for(int i=1;i<=a;i++)
            for(int j=1;j<=b;j++) {
                scanf("%d",&num[i][j]);
                sum+=num[i][j];
            }
        memset(f,-1,sizeof(f));
        double mx = dp(1,1,a,b,n) * 1.0;
        double average = sum * 1.0 / n;
        double ans = sqrt ( mx / n - 2.0* sum * average / n + average * average );
        printf("%.2f\n",ans);
    }
     
    return 0;
}
