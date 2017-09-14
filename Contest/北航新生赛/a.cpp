#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n,m;
bool v[555];
int a[111];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1;i<n;i++){
			scanf("%d",a+i);
			sum+=a[i];
		}
		memset(v,0,sizeof(v));
		v[sum]=1;
		for(int i=1;i<n;i++)
			for(int j=sum;j<=m;j++)
				for(int k=a[i];k*2<=m-j;k+=a[i]){
					if(v[j]) v[k*2+j]=1;
				}
        bool flag=0;
        for (int i=1;i<=m;i++){
            if(!v[i]){
                if (flag) printf(" ");
                flag=1;
                printf("%d",i);
            }
        }
        puts("");
	}
	return 0;
}
