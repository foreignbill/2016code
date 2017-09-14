#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int num[111111],a[111111]; 


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",num+i);
	for(int i=1;i<=n;i++) a[i]=num[i]-i;
	
	
	return 0;
} 
