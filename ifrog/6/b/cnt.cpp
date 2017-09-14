#include <cstdio>

int main(){
	int ans=0;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++){
					if(i==1||j==1||k==1||l==1) continue;
					ans++;
				}
	printf("%d\n",ans);
	return 0;
} 
