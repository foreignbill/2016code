#include<stdio.h>

int a[500],b[500]; 
int v[500];
int main(){
    int n,i,j;
	while (scanf("%d",&n)!=EOF){
	 	if (n==0) break;

	 	for (i=1;i<=n;i++){v[i]=0; a[i]=0;}
	 	for (i=1;i<=n;i++){
	 	 	scanf("%d",&a[i]);
	 	 	if (a[i]<0){
	 	 	    a[i]=abs(a[i]);
	 	 		v[a[i]]=1;
	 	 	}
	 	 }
	 	 
	 	 int t;
	 	 for(i=1;i<n;i++)
          for(j=i+1;j<=n;j++)
            if(a[j]<a[i]){t=a[i];a[i]=a[j];a[j]=t;}//Ñ¡ÔñÅÅÐò 
        
	 	 for (i=n;i>1;i--)
		    if (v[a[i]]==0) printf("%d ",a[i]);
		    else printf("%d ",-a[i]);
	 	 if (v[a[1]]==0) printf("%d\n",a[1]);
		    else printf("%d\n",-a[1]);
	 }
	 return 0;
} 
