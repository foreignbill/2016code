#include <bits/stdc++.h>
using namespace std;
int dian[11111];
struct node{
	int l,r;
}cur[11111];
bool cmp(node t1,node t2){
	return ((t1.l<t2.l)||((t1.l==t2.l)&&(t1.t<t2.r)));
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&dian[i]);
	for(int j=1;j<=m;j++) scanf("%d%d",&cur[i].l,&cur[i].r); 
	sort(dian+1,dian+1+n);
	sort(cur+1,cur+1+m,cmp);
	
	int ans=0;
	int tp=1;
	for(int i=2;i<=n;i++){
		
	}
	
	return 0;
} 
