#include <cstdio>

using namespace std;

int num[111111];
double ans[111111];

int main(){
	freopen("d.out","w",stdout);
	
	double last=0.0,now=0.0;
	int top=0;
	
	for(long long i=1;i<=1000000;i++){
		/*now+=1.0/i * 1.0 / i;
		if(now-last>=0.00001){
			top++;
			num[top]=i;
			ans[top]=now;
			last=now;
		}*/
		now+=1.0/i * 1.0 / i;
		printf("%d %.5f\n",i,now); 
	}
	
	for(int i=1;i<=top;i++) printf("%d %.5f \n",num[i],ans[i]);
	
	return 0;
}
