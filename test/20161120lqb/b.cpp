#include <cstdio>
#include <iostream>
using namespace std;
long long a,b,p;
long long bigpow(long long x, long long y)
{
	long long ret = 1;
	long long tmp = x;
	while (y > 0)
	{
		if (y & 1) ret = (ret%p)*(tmp%p)%p;
		y >>= 1;
		tmp = (tmp%p) * (tmp%p) % p;
	}
	return ret;
}

int main(){
	cin >>a>>b>>p;
	cout << bigpow(a,b)<<endl;
	return 0;
}
