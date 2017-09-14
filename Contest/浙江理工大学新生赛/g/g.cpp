#include <bits/stdc++.h>
using namespace std;
int stu[1111];
int ans[1111];
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(stu,0,sizeof(stu));
		int n,x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			stu[x]++; 
		}
		int mx=0;
		ans[0]=0;
		for(int i=0;i<=1000;i++){
			if(mx<stu[i]){
				mx=stu[i];
				ans[0]=1;
				ans[ans[0]]=i;
			}
			else if(mx==stu[i]){
				ans[0]++;
				ans[ans[0]]=i;
			}
		}
		for(int i=1;i<=ans[0];i++){
			if(i-1) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
	
	return 0;
} 
