#include <cstdio>
#include <cstring>
#define LL long long

using namespace std;

LL f[20][10][2];
LL base[20];

LL getans(LL x){
	LL tt=0;
	while(x>0){
		base[0]++;
		base[base[0]]=x%10;
		x/=10;
	}
	LL now=base[0],maxn=base[0];
	
	
	
}

int main(){
	LL L,R,T;
	
	for(int i=0;i<=9;i++){
		if(i%2==0) f[1][i][0]=0,f[1][i][1]=i/2+1;
		if(i%2==1) f[1][i][1]=i/2+1,f[1][i][0]=0;
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
		while(T--){
			memset(base,0,sizeof(base));
			scanf("%I64d%I64d",&L,&R);
			int ans=getans(R);
			ans-=getans(L-1);
			printf("%I64d\n",ans);
		}
	}
	
	return 0;
} 
