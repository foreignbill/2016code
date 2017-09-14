#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream> 

using namespace std;

struct node{
	int x,y;
}info[1111];

bool cmp2(node a,node b){
	if(a.x==b.x) return a.y>b.y;
	return a.x>b.x;
}

struct cmp{
	bool operator () (const int &a,const int &b){
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp> Q;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	int n,T;
	scanf("%d",&T);
	while(T--){
		while(!Q.empty()) Q.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&info[i].x);
		for(int i=1;i<=n;i++) scanf("%d",&info[i].y);
		sort(info+1,info+n+1,cmp2);
		for(int i=2;i<=n;i++){
			if(!(i&1)){
				Q.push(info[i].y);
			} else if(info[i].y>Q.top()){
				Q.pop();
				Q.push(info[i].y);
			}
		}
		long long ans=0;
		while(!Q.empty()){
			ans+=Q.top();
			Q.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
