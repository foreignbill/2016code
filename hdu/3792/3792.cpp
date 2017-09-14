#include <cstdio>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN=100001;
bool prime[MAXN];
int a[MAXN];
int sum[MAXN];
void init(){
    memset(prime,false,sizeof(prime));
    prime[0]=prime[1]=true;
    for(int i=2;i<MAXN;i++) if(!prime[i]){
        if(i>MAXN/i)continue;
        for(int j=i*i;j<MAXN;j+=i) prime[j]=true;
    }
} 

int lowbit(int x){
	return x&(-x);
}

void add(int k,int delta){
	while(k<=MAXN){
		sum[k]+=delta;
		k+=lowbit(k);
	}
}

int query(int k){
	int s = 0;
	while(k){
		s+=sum[k];
		k-=lowbit(k);
	}
	return s;
}

int main(){
	init();
	for(int i=5;i<=MAXN;i++)
		if(prime[i]==0&&prime[i-2]==0){
			add(i,1);
		}
	
	int n;
	while(cin>>n,n>=0){
		printf("%d\n",query(n));
	}
	return 0;
} 
