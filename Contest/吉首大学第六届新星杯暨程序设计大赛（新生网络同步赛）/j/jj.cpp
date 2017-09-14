#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>

using namespace std;

int a[10001];
bool v[10001];
int tot,ans;

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		ans=0,tot=0;
		int ansi;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			int mn=INT_MAX;
			for(int cnt=1;cnt<=n;cnt++)
				if(!v[cnt]){
					if(mn>a[cnt]){
						mn=a[cnt];
						ansi=cnt;
					}
				}
			v[ansi]=1; 
			ans+=tot;
			tot+=mn;
			printf("%d",ansi);
			if(i!=n) printf(" ");
		}
		puts("");
		double ans2=ans*1.0/n;
		printf("%.2lf\n",ans2);
	}	
	
	
	return 0;
} 
