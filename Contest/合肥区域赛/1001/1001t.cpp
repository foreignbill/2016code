#include<bits/stdc++.h>
using namespace std;
int link[2017][2017]; 
int main(){
	freopen("in.txt","r",stdin);
	int T,n;
	char ch;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d\n",&n);
		memset(link,0,sizeof link);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ch=getchar();
				if(ch=='-') continue;
				if(ch=='P') {
					link[i][j]=1;
				}
				if(ch=='Q') {
					link[i][j]=-1;
				}
			}
			ch=getchar();
		}
		bool ok=true;
		
		for(int u=1;u<=n&&ok;u++)
			for(int v=1;v<=n&&ok;v++)
				if(u!=v)
					for(int k=1;k<=n;k++)
						if(u!=k&&v!=k){
							if(link[u][k]==1&&link[k][v]==1)
								if(link[u][v]!=1){
									ok=false;
									break;
								}
							if(link[u][k]==-1&&link[k][v]==-1)
								if(link[u][v]!=-1){
									ok=false;
									break;
								}
						}

		if(ok) puts("T");
		else puts("N");
	}

	return 0;
}

