#include <cstdio>
long long n;
int main(){
	while(~scanf("%lld", &n)){
		long long i = 9;
		int b = 1;
		while (b != 2){
			if (n <= i){
				if (b == 1)
					puts("C");
				else
					puts("T");
				break;
			}
			if (b == 1)
				i = i * 2;
			else
				i = i * 9;
			b = 1 - b;
		}
	}
	return 0;
}
