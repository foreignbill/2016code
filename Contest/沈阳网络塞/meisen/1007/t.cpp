#include <cstdio>
#include <cstring>
#define LL long long

using namespace std;

LL f[25][10][2];
LL base[25];

LL getans(LL x){
	LL tt=0;
	memset(base,0,sizeof(0));
	if(x==0) return 1;
	while(x>0){
		base[0]++;
		base[base[0]]=x%10;
		x/=10;
	}
	LL now=base[0],maxn=base[0];
	
	
	for(int c=0;c<=base[now];c++)tt+=f[now][c][(c%2)^1];
	for(int c=2;c<=9;c+=2) tt-=f[now-1][c][0];
	for(int c=0;c<=9;c+=2) tt+=f[now-1][c][1];
	
	
	while(--now){
		if(base[now+1]%2==1){
			int t=0;
			while(base[now+t+1]%2==1&&now+t+1<=maxn) t++;
			int c; 
			if(t%2==1) for(c=9;c>base[now];c-=2) tt-=f[now][c][1];
		
			if(t%2==0) for(int c=9;c>base[now];c--) tt-=f[now][c][(c%2)^1];
		
		}	
		if(base[now+1]%2==0){
			int t=0;
			while(base[now+t+1]%2==0&&now+t+1<=maxn) t++;
			
			if(t%2==1) for(int c=9;c>base[now];c--)  tt-=f[now][c][0];
			
			if(t%2==0) for(int c=8;c>base[now];c-=2) tt-=f[now][c][1];
			
		}
	}
	return tt;
}

int main(){
	LL L,R,T;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<=9;i++){
		if(i%2==0) f[1][i][0]=0,f[1][i][1]=1;
		if(i%2==1) f[1][i][1]=1,f[1][i][0]=0;
	}
	
	for(int i=2;i<=15;i++)
		for(int j=0;j<=9;j++){
			if(j%2){
				for(int k=1;k<=9;k+=2)
					f[i][j][0]+=f[i-1][k][1];
				for(int k=0;k<=9;k++)
					f[i][j][1]+=f[i-1][k][(k%2)^1];
			}
			else{
				for(int k=0;k<=9;k++)
					f[i][j][1]+=f[i-1][k][0];
				for(int k=0;k<=9;k+=2)
					f[i][j][0]+=f[i-1][k][1]; 
			}
		}
		
	
	
	
	while(scanf("%I64d",&T)!=EOF){
		int num=0;
		while(T--){
			num++;
			memset(base,0,sizeof(base));
			scanf("%I64d%I64d",&L,&R);
			LL ans=getans(R);
			ans-=getans(L-1);
			printf("Case #%d: %I64d\n",num,ans);
		}
	}
	
	return 0;
} 
