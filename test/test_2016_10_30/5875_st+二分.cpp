#include <bits/stdc++.h>
using namespace std;
int st[100005][30];
int T,n,q;

inline int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x;
}

inline void getst(){
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = min(st[i + (1 << (j-1))][j - 1], st[i][j - 1]);
        }
    }
}

inline int rmqmin(int l, int r){
    int len = r - l + 1;
    int k = 0;
    while ((1 << (k + 1)) <= len) k++;
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

inline int getans(int l,int r){
	if(l==r) return st[l][0];
	int tt=st[l][0];
	l++;
	while(l<=r){
		int lt=l,rt=r;
		while(lt<rt){
			int mid=(lt+rt)>>1;
			if(rmqmin(lt,mid)<=tt) rt=mid;//如果[lt,mid]之间有值比当前值小，向左二分。 
			else if(rmqmin(mid+1,rt)<=tt) lt=mid+1;//如果左边比当前值大，则看右边，同左边处理。 
			else return tt;//如果后面区间的数字都比当前值大，后面没有有效取模操作，则return 
		}
		l=lt+1;//l右边比当前值小的第一个下标为lt，继续向右二分。 
		tt%=st[lt][0];
	}
	return tt;
}

int main(){
	freopen("t.txt","r",stdin);
	freopen("tp.out","w",stdout);
	T=read();
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) st[i][0]=read();
		getst();//st算法 
		
		int q;
		q=read();
		for(int i=1;i<=q;i++){
			int L,R;
			L=read();R=read();
			printf("%d\n",getans(L,R));
		}	
	}
	return 0;
} 

