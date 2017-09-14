#include <cstdio>
#include <cstring>
#include <cstdio>
#include <iostream> 

using namespace std;

struct node{
	int r,x;
}info[100005];

int main(){
	int T,h;
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	scanf("%d",&info[i].x);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(info[i].x>info[j].x){
					info[i].r=j;
					break;
				}
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&h);
			for(int j=1;j<=n;j=info[j].r){
				if(j==0||info[j].x==0) break;
				h%=info[j].x;
			}
			printf("%d\n",h);
		}
	}
	return 0;
} 
