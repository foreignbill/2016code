#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int num[1111111];
int   f[1111111];
struct node{
	int x,id;
}a[1111111];

bool cmp(node a,node b){
	if(a.x==b.x){
		return a.id<b.id;
	}
	return a.x<b.x;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=n;i++){
			a[i].x=num[i];
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)num[a[i].id]=i;
		f[n]=num[n];
		for(int i=n-1;i>=1;i--){
			f[i]=num[i];
			f[i]=min(f[i],f[i+1]);
		}	
		int ans=1,mx=-INT_MAX;
        for(int i=1;i<=n;i++){
            mx=max(mx,num[i]);
            if(f[i+1]>=mx) ans++;
        }
		printf("%d\n",ans);
		if(T!=0)puts("");
	}
	
	return 0;
}
