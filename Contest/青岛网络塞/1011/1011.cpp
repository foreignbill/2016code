#include <bits/stdc++.h> 
#define LL long long 
using namespace std;
struct node{
	int x,y,c,id;
}a[111111];
bool cmp(node t1,node t2){
	return (t1.y<t2.y)||((t1.y==t2.y)&&(t1.id<t2.id));
}
int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}
int pow(int l,int r,int y){
	int ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid].y<y){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}

int main(){
	freopen("input.txt","r",stdin);
	int T,n,m;
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++) {
			a[i].x=read();a[i].y=read();a[i].c=read();
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(int cnt=1;cnt<=m;cnt++){
			int x,y,w;
			x=read();y=read();w=read();
			LL min = LONG_LONG_MAX;
			int ansx,ansy,ansc,ansid;
			
			int tp=pow(1,n,y);
			
			for(int i=tp;i<=n;i++){
				LL dist = (long long)(a[i].x-x)*(a[i].x-x) + (long long)(a[i].y-y)*(a[i].y-y);
				if(a[i].c>w) continue;
				if(dist<min){
					min=dist;
					ansx=a[i].x;
					ansy=a[i].y;
					ansc=a[i].c;
				}
				else if(dist==min&&a[i].id<ansid){
					ansid=a[i].id;
					ansx=a[i].x;
					ansy=a[i].y;
					ansc=a[i].c;
				}
				if(abs(a[i].y-y)>min) break; 
			}
			for(int i=tp-1;i;i--){
				LL dist = (long long)(a[i].x-x)*(a[i].x-x) + (long long)(a[i].y-y)*(a[i].y-y);
				if(a[i].c>w) continue;
				if(dist<min){
					min=dist;
					ansx=a[i].x;
					ansy=a[i].y;
					ansc=a[i].c;
				}
				else if(dist==min&&a[i].id<ansid){
					ansid=a[i].id;
					ansx=a[i].x;
					ansy=a[i].y;
					ansc=a[i].c;
				}
				if(abs(a[i].y-y)>min) break; 
			}
			
			printf("%d %d %d\n",ansx,ansy,ansc);
		}
	}
	return 0;
}
