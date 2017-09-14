#include <cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	freopen("output.txt","w",stdout);
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		printf("%10d%10d",a,b);
		puts(gcd(a,b)-1?"    Bad Choice\n":"    Good Choice\n");
	}
	return 0;
}
