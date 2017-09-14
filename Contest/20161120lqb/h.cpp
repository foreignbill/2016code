#include <bits/stdc++.h>
using namespace std;
int N, m, v[30005], p[33];
int f[30005];
int main(){
    int ans;
    scanf("%d%d", &N, &m);
    for(int i=1; i<=m; i++){
        scanf("%d%d", &v[i], &p[i]);
    }
    
    for(int i=1;i<=m;i++)
    	for(int j=N;j>=0;j--)
    		if(j>=v[i])	f[j] = max(f[j],f[j-v[i]]+v[i]*p[i]);
    

    ans=-INT_MAX;
    for(int i=N; i>=0; i--){
        ans = max(f[i], ans);
    }
    printf("%d\n", ans);
    return 0;
}
