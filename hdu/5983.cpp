#include<bits/stdc++.h>
#define LL long long
using namespace std;
int a[10][10],c[10][10];
set<int>s;
void init(){
  for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
        a[i][j]=c[i][j];
}
int judge(){
    int f[7],ans=0;
    memset(f,0,sizeof(f));
    for(int i=1;i<=8;i+=2)
    if(a[i][3]==a[i][4]&&a[i][3]==a[i+1][3]&&a[i][3]==a[i+1][4]) f[i/2+1]=1;
    if(a[1][1]==a[1][2]&&a[1][1]==a[2][1]&&a[1][1]==a[2][2]) f[5]=1;
    if(a[1][5]==a[1][6]&&a[1][5]==a[2][5]&&a[1][5]==a[2][6]) f[6]=1;
    for(int i=0;i<7;i++)
        ans+=f[i];
    if(ans==6) return 1;
    return 0;
}
int up(){init();
    int b[10];
    for(int i=1;i<=8;i++){
        b[i]=a[i][4];
        if(i<=6)
            a[i][4]=a[i+2][4];
        else
            a[i][4]=b[9-i];
    }
    if(judge()) return 1;
    return 0;
}
int down(){init();
    int b[10];
    for(int i=8;i>=1;i--){
        b[i]=a[i][4];
        if(i>=3)
            a[i][4]=a[i-2][4];
        else
            a[i][4]=b[9-i];
    }
    if(judge()) return 1;
    return 0;
}
int left(){init();
    int b[10];
    b[1]=a[1][1];b[2]=a[1][2];
    a[1][1]=a[1][3];a[1][2]=a[1][4];a[1][3]=a[1][5];a[1][4]=a[1][6];
    a[1][5]=a[6][4];a[1][6]=a[6][3];
    a[6][4]=b[1];a[6][3]=b[2];
    if(judge()) return 1;
    return 0;
}
int right(){init();
    int b[10];
    b[3]=a[1][3];b[4]=a[1][4];
    a[1][3]=a[1][1];a[1][4]=a[1][2];a[1][1]=a[6][4];a[1][2]=a[6][3];
    a[6][4]=a[1][5];a[6][3]=a[1][6];
    a[1][5]=b[3];a[1][6]=b[4];
    if(judge()) return 1;
    return 0;
}
int lf(){init();
    int b[10];
    b[1]=a[8][3];b[2]=a[8][4];
    a[8][3]=a[1][5];a[8][4]=a[2][5];
    a[1][5]=a[3][4];a[2][5]=a[3][3];
    a[3][3]=a[1][2];a[3][4]=a[2][2];
    a[1][2]=b[2];a[2][2]=b[1];
    if(judge()) return 1;
    return 0;
}
int rf(){init();
    int b[10];
    b[1]=a[8][3];b[2]=a[8][4];
    a[8][3]=a[2][2];a[8][4]=a[1][2];
    a[1][2]=a[3][3];a[2][2]=a[3][4];
    a[3][3]=a[2][5];a[3][4]=a[1][5];
    a[1][5]=b[1];a[2][5]=b[2];
    if(judge()) return 1;
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        s.clear();
        for(int i=1;i<=8;i++)for(int j=3;j<=4;j++)scanf("%d",&c[i][j]),s.insert(c[i][j]);
        for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)scanf("%d",&c[i][j]),s.insert(c[i][j]);
        for(int i=1;i<=2;i++)for(int j=5;j<=6;j++)scanf("%d",&c[i][j]),s.insert(c[i][j]);
        init();
        if(s.size()==6){
               if(judge()){
                    printf("YES\n"); continue;
               }
               if(up()||down()||left()||right()||lf()||rf()){
                    printf("YES\n");
               }else printf("NO\n");
        }else printf("NO\n");

    }
    return 0;
}
