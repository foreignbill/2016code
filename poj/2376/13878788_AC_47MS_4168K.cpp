#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, T, M[1000050];
int main()
{
	cin >> N >> T;int a, b;
	for (int i = 0; i < N; i++) { scanf("%d%d", &a, &b); if (M[a] == 0)M[a] = b; else M[a] = max(M[a], b); }
	int nows = 1, cnt = 0, t, pre = 1, i;
	while (nows - 1 < T)
	{
		t = 0; i = pre;
		for ( ; i <= nows; i++)
			if (M[i] > t) { t = M[i]; pre = i; }
		if (t + 1 == nows) { cout << -1 << endl; return 0; }
		nows = t + 1;cnt++;
	}
	cout << cnt << endl;
	return 0;
}
