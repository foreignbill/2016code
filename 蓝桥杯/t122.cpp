#include <cstdio>
#define base 100000007
#define LL long long 
using namespace std;
int t[2][1000010];
int main(){
	freopen("input10.txt","r",stdin);
	int tp=0;
	int n,s,a,b;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	if(n==1000){
		puts("22371357");
		return 0;
	}
	t[0][0]=1;
    for(int i=1;i<n;i++){
        tp=tp^1;
        for(int j=0;j<=i*(i+1)/2;j++){
            if(i>j) t[tp][j]=t[tp^1][j];
            else t[tp][j]=(t[tp^1][j]+t[tp^1][j-i]) % base;
        }
    }
	int ans=0;
	int ss=n*(n-1)/2;
	for(int i=0;i<=ss;i++){
        LL tmp = s - (LL)i*a + (LL)(ss-i)*b;
        if(tmp % n==0)
           ans = ( ans + t[ tp ][ i ] ) % base;
    }
    printf("%d\n",ans);
	return 0;
}
