#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int T;
	char st[111];
	scanf("%d",&T);getchar();
	while(T--){
		int n,t;
		scanf("%d %s",&n,st);getchar();
		bool used[111]={0};
		for(int i=0;i<strlen(st);i++) used[st[i]-'0']=1;
		
		for(int i=1;i<=9;i++){
			if(!used[i]){
				printf("%d",i);
				used[i]=1;
				break;
			}
		}
		
		for(int cnt=1;cnt<=n-strlen(st)-1;cnt++){
			for(int i=0;i<=9;i++){
				if(!used[i]){
					printf("%d",i);
					used[i]=1;
					break;
				}
			}
		}
		printf("%s\n",st);
	} 
	
	return 0;
}
