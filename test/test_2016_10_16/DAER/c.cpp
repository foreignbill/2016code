#include <bits/stdc++.h>

using namespace std;

char ch[111111],tmp[111111];

int main(){
	int n;
	scanf("%d\n",&n);
	
	for(int i=1;i<=n;i++) scanf("%c",&ch[i]);
	
	int t1=0,t2=0;
	for(int i=1;i<=n;i++){
		if(i%2==1)
			if(ch[i]=='b') t1++; 
		if(i%2==0)
			if(ch[i]=='r') t2++;
	}
	int ans=max(t1,t2);
	
	t1=0,t2=0;
	
	for(int i=1;i<=n;i++){
		if(i%2==1)
			if(ch[i]=='r') t1++; 
		if(i%2==0)
			if(ch[i]=='b') t2++;
	}
	ans=min(ans,max(t1,t2));
	
	printf("%d\n",ans);
	
	return 0;
}
