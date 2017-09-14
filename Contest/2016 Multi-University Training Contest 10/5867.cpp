#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int bit1[] = {4,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int bit2[] = {0,0,6,6,5,5,5,7,6,6};
int hundred, thousand;
int cnt[1100];
void solve(){
	hundred = 7; thousand = 8;
    cnt[1000] = 11;
    for(int i=1; i<1000; i++) {
        if(i < 20) cnt[i] = bit1[i];
        else if(i < 100){
            int m = i;
            cnt[i] = bit2[m/10];
            if(m%10) cnt[i] += bit1[m%10];
        }
        else {
            int m = i;
            cnt[i] = bit1[m/100] + hundred;
            if(!(m%100)) continue;
            cnt[i] += cnt[m%100] + 3;
        }
    }
    for(int i=1; i<=1000; i++) cnt[i] += cnt[i-1];
}
int main(){
	solve(); 
    int T; 
	cin>>T;
    while(T--){
        int n;
		scanf("%d",&n);
        printf("%d\n",cnt[n]);
    }
    return 0;
}
