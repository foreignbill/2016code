#include <cstdio>
using namespace std;
#define LL long long
LL a,c,x0,n,g,m;
struct Matrix{
	LL m[2][2];
}base,temp,first; 

LL quickadd(LL a, LL b) {
    LL ans = 0;
    a %= m; b %= m;
    while(b > 0) {  
        if(b & 1) ans = (ans + a) % m;  
        a = (a + a) % m;  
        b >>= 1;
    }
    return ans;
}

Matrix mul(Matrix a, Matrix b) {
    Matrix ans;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            LL sum = 0;
            for(int k = 0; k < 2; k++)
                sum = (sum + quickadd(a.m[i][k], b.m[k][j])) % m;
            ans.m[i][j] = sum;
        }
    return ans;
}

Matrix pow(Matrix a, LL n) {
    Matrix p = {{1, 0, 0, 1}};
    while(n > 0) {
        if(n & 1) p = mul(p, a);
        a = mul(a, a);
        n /= 2;
    }
    return p;
}


int main(){
	scanf("%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
	base = (Matrix) {{a, 0, 1, 1}};
	first= (Matrix) {{x0,c,0,1}};
	Matrix ans = mul(first,pow(base,n));
	printf("%lld",ans.m[0][0] % g);
	return 0;
}
