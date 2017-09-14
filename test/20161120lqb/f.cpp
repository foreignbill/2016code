#include <cstdio>
using namespace std;
int main(){
	int s;
	scanf("%d",&s);
	for(int i=1;i<=s;i++){
		for(int j=i+1;j<=s;j++){
			int sum = (i+j)*(j-i+1)/2;
			if(sum==s) printf("%d %d\n",i,j);
			if(sum>s) break;
		}
	}
	return 0;
} 
