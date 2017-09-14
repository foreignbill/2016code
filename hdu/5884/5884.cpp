#include <bits/stdc++.h>

using namespace std;

int a[111111],b[111111];
int n,t;


bool check(int mid){
	 int f1=1,r1=n;f2=r2=0;
	 int cost=0;
	 if((n-1)%(k-1)!=0)
	 	for(int i=1;i<=(n-1)%(k-1);i++){
	 		f2++;r2++;
	 		b[f2]+=a[f1];
	 		f1++;
	 	}
	 	
	 
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&t);
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int f=1,r=n,ans;
		while(f<=r){
			int mid=(f+r)/2; 
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}
			else
			{
				f=mid+1;
			}
		}
	}
	return 0;
}



/*
            while (head <= tail)  
            {  
                mid = (head + tail) / 2;  
                if (Check(mid))  
                {  
                    res = mid;  
                    tail = mid - 1;  
                }  
                else  
                {  
                    head = mid + 1;  
                }  
            }  
*/

