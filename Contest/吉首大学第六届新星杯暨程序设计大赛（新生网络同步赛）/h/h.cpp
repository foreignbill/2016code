#include <iostream>
#include <cstdio>
using namespace std;
int main (){
	int T;
	cin>>T;
	while(T--){
		int m,x,y,z;
		scanf("%d%d%d%d",&m,&x,&y,&z);
		double time;
		time = (double)(m*x)/(y-x);
		double res;
		res=z*time;
		printf("%.2lf\n",res);
	}
	return 0;
}
