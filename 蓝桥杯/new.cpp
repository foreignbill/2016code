#include<bits/stdc++.h>
#define MAX 1000010
#define N 100010
using namespace std;
int C1[MAX],C2[MAX],b[MAX];
int num[N];
long long total[N],ans;
int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x;
}
int lowbit(int x){
	return x&(x^(x-1));
}
void add(int pos,int num,int *C){
	while(pos<=MAX){
		C[pos]+=num;
		pos+=lowbit(pos);
	}
}
int Sum(int pos,int *C){
	int sum=0;
	while(pos>0){
		sum+=C[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main(){
	freopen("input4.txt","r",stdin);
	int n;
	n=read();
	for(int i=0;i<n;i++){
		num[i]=read();
		add(num[i]+1,1,C1);
		b[i]=i-Sum(num[i],C1);
		b[i]=b[i]-(Sum(num[i]+1,C1)-Sum(num[i],C1)-1);
	}
	for(int i=n-1;i>=0;i--){
		add(num[i]+1,1,C2);
		b[i]=b[i]+Sum(num[i],C2);
	}
	ans=0;
	for(int i=0;i<n;i++){
		ans+=(b[i]+1)*b[i]/2;
	}
	cout<<ans<<endl;	
	return 0;
 } 
