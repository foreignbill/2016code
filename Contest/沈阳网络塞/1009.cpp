#include <stdio.h>
#include <iostream>
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <cctype>
#include <climits>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <functional>
/*int类型最大值INT_MAX，short最大值为SHORT_MAX
long long最大值为LONG_LONG_MAX*/
//cout << "OK" << endl;
#define _clr(x,y) memset(x,y,sizeof(x))
#define _inf(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double EULER = 0.577215664901532860;
const double PI = 3.1415926535897932384626;
const double E = 2.71828182845904523536028;

typedef long long LL;
LL gcd(LL a,LL b){return b == 0 ? a : gcd(b,a%b);}
LL a[1000010]={},b[1000010]={},f[310][310],s[1000010]={},t[310][310]={},g[310][310]={};
int main() {  
    //ios_base::sync_with_stdio(false); cin.tie(0);
    LL T,n,m,L,R;
    cin >> T;
    while (T--){
        cin >> n;
        memset(f,0,sizeof f);
        memset(s,0,sizeof s);
        memset(t,0,sizeof t);
        memset(g,0,sizeof g);
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=1;i<=n;i++) cin >> b[i];        
        for (LL i=1;i<=n;i++){
            s[i]=s[i-1]+b[i];
        }
        for (LL i=1;i<n;i++) if (gcd(a[i],a[i+1])!=1) f[i][i+1]=1;
        for (LL i=1;i<=n;i++){
            for (LL j=i+1;j<=n;j++) if (gcd(a[i],a[j])!=1) t[i][j]=1;
        }
        for (LL k=3;k<n;k=k+2){
            for (LL i=1;i<=n-k;i++){
                if (t[i][i+1] && f[i+2][i+k]) f[i][i+k]=1; 
                if (t[i+k-1][i+k] && f[i][i+k-2]) f[i][i+k]=1; 
                if (t[i][i+k] && f[i+1][i+k-1]) f[i][i+k]=1; 
            }
        }
        for (LL k=1;k<n;k++){
            for (LL i=1;i<=n-k;i++){
                if (f[i][i+k]){
                    g[i][i+k]=s[i+k]-s[i-1];
                    continue;
                }
                else g[i][i+k]=max(g[i+1][i+k],g[i][i+k-1]);
                for (LL j=i+1;j+1<i+k;j++){
                    g[i][i+k]=max(g[i][j]+g[j+1][i+k],g[i][i+k]);
                }
            }
        }
        cout << g[1][n] << endl;
    }
}  
