//Memory: 140 KB		Time: 0 MS
//Language: C++		Result: Accepted
#include <cstdio>
using namespace std;
int main(){
	double ans=0.0,x;
	for(int i=1;i<=12;i++){
		scanf("%lf",&x);
		ans+=x;
	}
	printf("$%.2lf\n",ans * 1.0 / 12);
	return 0;
}

