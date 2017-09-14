#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 50005;
int info[MAXN][3];
int succeed[MAXN];
int main(){
    int i,j,n,T,m;
    scanf("%d",&T);
    while(T--){
        memset(succeed,0,sizeof(succeed));
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d",&info[i][0],&info[i][1]);
            info[i][2]=1;
        }
        for(i=m;i>=1;i--){
            if(info[i][2]==0) continue;
            else if(info[i][0]==3) info[info[i][1]][2]=0;
        }
        for(i=1;i<=m;i++){
            if(info[i][2]==0) continue;
            else
            {
                if(info[i][0]==1) succeed[info[i][1]]=1;
                else if(info[i][0]==2) succeed[info[i][1]]=0;
            }
        }
        int sum=0;
        for(i=1;i<=n;i++)if(succeed[i]==1) sum++;
        printf("%d\n",sum);
        int flag=0;
        for(i=1;i<=n;i++){
        	if(flag&&succeed[i]==1) printf(" ");
        	if(succeed[i]==1) printf("%d",i);
        	flag=1;
        }
        puts("");
    }
}
