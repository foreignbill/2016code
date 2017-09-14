#include <cstdio>
using namespace std;
int main(){
	int a,b;
	char ch;
	scanf("%d%c%d",&a,&ch,&b);
	if(ch=='+') printf("%d\n",a+b);
	if(ch=='-') printf("%d\n",a-b); 
	return 0;
}
