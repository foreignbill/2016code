#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long FindFirstBitIs1 (long long num){
    long long indexBit = 0;
    while ((num & 1) == 0 && indexBit < 32){
        num >>= 1;
        ++indexBit;
    }
    return indexBit;
}

long long IsBit1 (long long data, unsigned long long indexof1){
    data >>= indexof1;
    return data & 1;
}
 
void FindNumsAppearOnce (long long data[], long long n, long long &num1, long long &num2){
    long long result = 0;
    long long i;
    for (i=0; i<n; ++i){
        result ^= data[i];
    }
    unsigned long long indexof1 = FindFirstBitIs1 (result);
    num1 = 0;
    num2 = 0;
    for (i=0; i<n; ++i){
        if (IsBit1 (data[i], indexof1))
            num1 ^= data[i];
        else
            num2 ^= data[i];
    }
}

int main(){	
	int T;
	cin>>T;
	while(T--){
		long long num1 = 0,num2 = 0;
		long long n;
		scanf("%lld",&n);
		long long *a=new long long[n];
		for(long long i=0;i<n;i++){
			scanf("%lld",&a[i]); 
		}
		FindNumsAppearOnce(a,n,num1,num2);
		printf("%lld %lld\n",min(num1,num2),max(num1,num2));
		delete[] a;
	}
	return 0;
}
