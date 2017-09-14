#include <cstdio>
#include <cstring>
using namespace std;
int prime[65536];
int s[100000],ans;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}
void printprime(){
	for(int i=2;i<=65536*2;i++){
		if(isprime(i)){
			prime[++prime[0]]=i;
		}
	}
}
int main(){
	printprime();
	int a,b,cnt,top,T;
	cnt=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		b=1;
		memset(s,0,sizeof(s));
		int tmp=a;
		top=0;
		for(int i=1;i<=prime[0];i++){
			top++;
			if(tmp%prime[i]!=0) continue;
			while(tmp%prime[i]==0){
				s[top]++;
				tmp/=prime[i];
				if(tmp==1) break;
			}
		}
		if(tmp>1){
			top++;
			s[top]++;
		}
		ans=1;
		for(int i=1;i<=top;i++){
			int bb=(s[i]+2)*(s[i]+1)/2;
			int tt=bb*bb;
			ans=ans*tt;
		}
	    printf("%d\n",ans);
	}
	return 0;
}
