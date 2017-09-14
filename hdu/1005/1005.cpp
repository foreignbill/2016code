#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int P = 7;
const int N=13;
ll n,m;

struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++){
                tmp[i][j]=0;
                for (int k=0;k<=n+1;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (ll x){
        matrix ret;
        for (int i=0;i<=n+1;i++)ret[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp*=tmp){if(x&1)ret *=tmp;}
        return ret;
    }
};

int main(){
	int a,b,num;
	n=2;
	while(cin>>a>>b>>num,(a||b||num)){
		matrix base;
		base[0][0]=a;base[0][1]=1;base[1][0]=b;base[1][1]=0;
		base = base ^ (num-1);
		printf("%d\n",(base[0][1]+base[1][1])%7);
	}
	return 0;
} 

