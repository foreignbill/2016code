#include <cstdio>
#include <cstring>

int c[45][45],binary[50];

void Print_C(){
	for(int i=1;i<=33;i++)
	   for(int j=1;j<=i;j++){
	   	 if(j==1||j==i) c[i][j]=1;
	   	 else c[i][j]=c[i-1][j]+c[i-1][j-1];
	   }
	c[0][0]=1;
	return;
}

void Get_bin(int x){
    while(x){
    	binary[0]++;
    	binary[binary[0]]=x%2;
    	x=x/2;
    }
    return;
}

int Dp(int x){
	memset(binary,0,sizeof(binary));
	int ans=0;
	Get_bin(x);
	for(int i=1;i<binary[0]-1;i++)
	    for(int j=(i+1)/2;j<=i;j++) ans+=c[i][j];
	
	int zeap=0;
	for(int i=binary[0]-1;i>=1;i--)
	   if(binary[i])
	      for(int j=(i+1)/2-(zeap+1);j<i;j++)
	         ans+=c[i-1][j];
	   else zeap++;
	return ans;
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	Print_C();
	printf("%d\n",Dp(b+1)-Dp(a));
	return 0;
}