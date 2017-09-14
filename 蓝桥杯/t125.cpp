#include <bits/stdc++.h>
#define M 105
using namespace std;
int g[M][M];
char dd[] = {'L', 'U', 'R', 'D','L'};
char dt[] = {'L', 'D', 'R', 'U','L'};
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j, x, y, stp;
	char ch;
	for(i = 0; i < n; i ++)
		for(j = 0; j < m; j ++)
			scanf("%d", &g[i][j]);
	scanf("%d %d %c %d", &x, &y, &ch, &stp);
	while(stp--){
		if(g[x][y]){
			g[x][y] = 0;
			for(i = 0; i < 4; ++ i)
				if(dd[i] == ch) break;
			ch = dd[i+1];
			if(ch=='L') y--;
			if(ch=='R') y++;
			if(ch=='U') x--;
			if(ch=='D') x++;
		}
		else{
			g[x][y] = 1;
			for(i = 0; i < 4; ++ i)
				if(dt[i] == ch) break;
			ch = dt[i+1];
			if(ch=='L') y--;
			if(ch=='R') y++;
			if(ch=='U') x--;
			if(ch=='D') x++;
		}	
	}
	printf("%d %d\n", x, y);
	return 0;
}
