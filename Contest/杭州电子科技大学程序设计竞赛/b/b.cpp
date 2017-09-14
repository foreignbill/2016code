#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int f[20][20];//bit num

int base[20];

int main(){
	
	for(int i=1;i<=9;i++) f[1][i]=1;
	for(int i=2;i<=11;i++)
		for(int j=1;j<=9;j++)
				for(int k=j;k<=9;k++)
					f[i][j] += f[i-1][k];
	int T,x;
	cin>>T;
	while(T--){
		cin>>x;
		base[0]=0;
		while(x){
			base[++base[0]]=x%10;
			x/=10;
		}
		int len=base[0];
		base[len+1]=0;
		int ans = 0;
		/*for(int i=1;i<=base[len];i++) ans += f[len][i];
		for(int i=len-1;i>=1;i--){
			for(int k=max(base[i+1],base[i]+1);k<=9;k++) ans -= f[i][k];
			
			for(int k=1;k<=9;k++) ans += f[i][k];
		}*/
		
		for(int i=1;i<len;i++)  
        	for(int j=1;j<10;j++)  ans+=f[i][j];
        	
		for(int j=1;j<base[len];j++)  ans+=f[len][j];
		
		for(int i=len-1;i;i--){
        	for(int j=0;j<base[i];j++)
            	if(base[i+1]<=j)  
                	ans+=f[i][j]; 
            if(base[i]>base[i+1]) break;    	
        }
		printf("%d\n",ans);
	}
	
	return 0;
} 
