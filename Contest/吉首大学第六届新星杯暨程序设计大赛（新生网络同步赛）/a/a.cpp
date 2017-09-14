#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define LL long long

using namespace std;

LL num[100001];

LL getNum(LL n) {
	LL i, j, cnt = 0, ans = 0;
	for(i = 1; i*i < n; i++) {
		if(n%i == 0) {
			num[cnt++] = i;
			num[cnt++] = n/i;
		}
	}
	if(i*i==n) {
		num[cnt++]=i;
	}
	for(i = 0; i < cnt; i++) {
		for(j = 0; j < cnt; j++) {
			if(n%(num[i]*num[j]) == 0) {
				ans++;
			}
		}
	}
	return ans;
}
int main () {
	LL n, m;
	int t;
	t=0;
	while(scanf("%lld", &n) != EOF) {
		m = getNum(n);
		printf("Case %d: %lld\n", ++t, m);
	}
	return 0;
}
