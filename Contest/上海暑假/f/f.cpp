#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char a[2000],b[2000],ans[2000],temp[2000],tt[2000];
int num[2000];
int alen,blen; 

int main(){
	scanf("%s%s",&a,&b);
	alen=strlen(a);blen=strlen(b); 
	int top=0;
	ans[top]=b[0];num[top]++;
	int cnt=0;
	while(cnt<blen){
		while(b[cnt+1]==b[cnt]){
			cnt++;
			num[top]++;
		}
		top++;cnt++;
		ans[top]=b[cnt];
		num[top]++;
	}
	bool pan=false;

	
	return 0;
} 
