#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[2222];

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++) scanf("%d",a+i);
		sort(a+1,a+1+n+n);
		int ans=0;
		for(int i=n*2;i>=n+1;i--) ans+=(a[i]-a[2*n-i+1]);
		printf("%d\n",ans);
	} 
	return 0;
}/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1005];

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+2*n);
        
        long long ans=0;
        for (int i=1;i<=n;i++)
        ans=ans+abs(a[i]-a[2*n-i+1]);
        printf("%lld\n",ans);
    }
    return 0;
}*/
