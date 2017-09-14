#include <cstdio>

using namespace std;

struct matrix{
	int m[3][3];
};

int m,a,c,x0,g,n;
int answer[3];
matrix final,p0;

matrix pow(int ti){
	if(ti==1)	return p0;
	if(ti%2==1){
		matrix temp=pow(ti/2);
		matrix ans;
		ans.m[1][1]=(temp.m[1][1]*temp.m[1][1]+temp.m[1][2]*temp.m[2][1])%m; 
		ans.m[1][2]=(temp.m[1][1]*temp.m[1][2]+temp.m[1][2]*temp.m[2][2])%m;
		ans.m[2][1]=(temp.m[2][1]*temp.m[1][1]+temp.m[2][2]*temp.m[2][1])%m;
		ans.m[2][2]=(temp.m[2][1]*temp.m[1][2]+temp.m[2][2]*temp.m[2][2])%m;
		ans.m[1][1]=(ans.m[1][1]*a+ans.m[1][2]*0)%m; 
		ans.m[1][2]=(ans.m[1][1]*c+ans.m[1][2]*1)%m;
		ans.m[2][1]=(ans.m[2][1]*a+ans.m[2][2]*0)%m;
		ans.m[2][2]=(ans.m[2][1]*c+ans.m[2][2]*1)%m;		
		return ans;
	}
	if(ti%2==0){
		matrix temp=pow(ti/2);
		matrix ans;
		ans.m[1][1]=(temp.m[1][1]*temp.m[1][1]+temp.m[1][2]*temp.m[2][1])%m; 
		ans.m[1][2]=(temp.m[1][1]*temp.m[1][2]+temp.m[1][2]*temp.m[2][2])%m;
		ans.m[2][1]=(temp.m[2][1]*temp.m[1][1]+temp.m[2][2]*temp.m[2][1])%m;
		ans.m[2][2]=(temp.m[2][1]*temp.m[1][2]+temp.m[2][2]*temp.m[2][2])%m;
		return ans;
	}
}

int main(){
	scanf("%d%d%d%d%d%d",&m,&a,&c,&x0,&n,&g);
	p0.m[1][1]=a;p0.m[1][2]=c;
	p0.m[2][1]=0;p0.m[2][2]=1; 
	final=pow(n);
	int xn=(final.m[1][1]*x0+final.m[1][2])%g;
	
	printf("%d\n",xn % g);
	return 0;
} 
