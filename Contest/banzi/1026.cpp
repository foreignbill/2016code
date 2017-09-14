#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int a,b;
int f[100][11];

int find(int x){
	int base[111],tt=0;
	memset(base,0,sizeof(base));
	while(x>0){
		base[0]++;
		base[base[0]]=x%10;
		x/=10;
	}
	int tmp=base[0];
	int tot=f[tmp][base[tmp]];
	for(int i=2;i<=tmp;i++)
		for(int j=0;j<=9;j++)
			if(j-base[tmp-i+1]>=2) tot-=f[tmp-i+1][j];
	return tot;
}

int main(){
	scanf("%d%d",&a,&b);
	for(int i=0;i<=9;i++) f[1][i]=1;

	for(int i=2;i<=10;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2) f[i][j]+=f[i-1][k];
				
	int ans=find(b)-find(a-1);
	
	printf("%d\n",ans);
	
	return 0;
} 
