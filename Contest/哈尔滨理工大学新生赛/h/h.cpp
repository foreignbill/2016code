#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int BASE=90001;
int info[111111][6];
vector<int> HASH[BASE];

bool check(int a, int b){
	for(int i=0;i<6;i++){
		bool ok1=true,ok2=true;
		for(int cnt=0;cnt<6;cnt++)
			ok1=ok1&&(info[a][cnt]==info[b][(i+cnt)%6]);
		for(int cnt=0;cnt<6;cnt++)
			ok2=ok2&&(info[a][cnt]==info[b][(i+(6-cnt))%6]);
		if(ok1||ok2) return 1;
	}
	return 0;
}

int main(){
	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
		bool ok=0;
		int n;
		int i,j;
		scanf("%d",&n);
		for(int i=0;i<n;i++) 
			for(int j=0;j<6;j++)
				cin>>info[i][j];
		int sum,key;
		for(int i=0;i<n&&ok==0;i++){
			sum = 0;
			for(int j=0;j<6;j++) sum+=info[i][j];
			key=sum%BASE;
			for(int j=0;j<HASH[key].size();j++){
				if(check(HASH[key][j], i)){
					puts("Twin snowflakes found.");
					ok=1;
					break;
				}
			}
			HASH[key].push_back(i);
		}
		if(ok) continue;
		puts("No two snowflakes are alike.");
	}
	return 0;
}

