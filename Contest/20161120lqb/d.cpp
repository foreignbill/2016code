#include <bits/stdc++.h>
using namespace std;
bool dian[50009];
bool v[11111];
struct node{
	int l,r;
}sec[11111];
bool cmp(node t1,node t2){
	return ((t1.l<t2.l)||(t1.l==t2.l)&&(t1.r<t2.r));
}
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	memset(dian,0,sizeof(dian));
	memset(v,0,sizeof(v)); 
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		dian[x]=1;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&sec[i].l,&sec[i].r);
	}
	sort(sec+1,sec+1+m,cmp);
	int ans=0,E;
	for(int i=1;i<=m;i++){
		int mx=-INT_MAX;
		if(!v[i]){
			for(int j=sec[i].l;j<=sec[i].r;j++){
				if(dian[j]){
					int tot=0;
					for(int k=i+1;k<=m;k++){
						if(sec[k].l<=j&&j<=sec[k].r){
							tot++;
						}
						else break;
					}
					if(tot>mx){
						mx=tot;
						E=j;
					}
				}
			}
			ans++;
			for(int k=i+1;k<=m;k++){
				if(sec[k].l<=E&&E<=sec[k].r){
					v[k]=1;
				}
				else break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
