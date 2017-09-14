#include <cstdio>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        for(int i=1;i<=n;i++) sum+=i;
        printf("%d\n\n",sum);
    }
    return 0;
}
