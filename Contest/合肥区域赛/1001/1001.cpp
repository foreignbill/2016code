#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<int> e1[2017],e2[2017];//e1 P e2 Q
struct node{
	int id,step,fa;
	node(int _id=0,int _step=0,int _fa=0):id(_id),step(_step),fa(_fa){}
}Q[2000000];

int find1(int x,int y){
	for(int i=0;i<e1[x].size();i++){
		if(e1[x][i]==y) return 1;
	}
	return 0;
}

int find2(int x,int y){
	for(int i=0;i<e2[x].size();i++){
		if(e2[x][i]==y) return 1;
	}
	return 0;
}

int main(){
	freopen("in.txt","r",stdin);
	int T,n;
	char ch;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d\n",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%c",&ch);
				if(ch=='-') continue;
				if(ch=='P') {
					e1[i].push_back(j);
				}
				if(ch=='Q') {
					e2[i].push_back(j);
				}
			}
			scanf("\n");
		}
		bool ok=true;
		for(int i=1;i<=n;i++){
			Q[i].id=i;
			Q[i].step=0;
			Q[i].fa=0;
		}
		int f=1,r=n;
		while(f<=r&&ok){
			node tmp=Q[1];
			f++;
			for(int i=0;i<e1[tmp.id].size();i++){
				int now = e1[tmp.id][i]; 
				if(tmp.step==1){
					if(find1(tmp.fa,now)==0){
						ok=false;
						break;
					}
				}
				if(tmp.step==0){
					node tt;
					tt.id=now;
					tt.fa=tmp.id;
					tt.step=tmp.step+1;
					bool check=1;
					for(int j=f-1;j<=r;j++) 
						if(Q[j].id==now){
							check=0;
							break;
						}
					if(check) Q[++r]=tt;
				}
			}
		}
		f=1;r=n;
		while(f<=r&&ok){
			node tmp=Q[1];
			f++;
			for(int i=0;i<e2[tmp.id].size();i++){
				int now = e2[tmp.id][i]; 
				if(tmp.step==1){
					if(find2(tmp.fa,now)==0){
						ok=false;
						break;
					}
				}
				if(tmp.step==0){
					node tt;
					tt.id=now;
					tt.fa=tmp.id;
					tt.step=tmp.step+1;
					bool check=1;
					for(int j=f-1;j<=r;j++) 
						if(Q[j].id==now){
							check=0;
							break;
						}
					if(check) Q[++r]=tt;
				}
			}
		}
		if(ok) puts("T");
		else puts("N");
	}
	
	
	return 0;
}

