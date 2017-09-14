#include <stdio.h>

void fun(char *str,char *p[],int n){
	int i,j;
	int len=0;
	str[0]='\0';
	for(i=0;i<4;i++){
		
		for(j=0;(*(p+i))[j]!='\0';j++){
			str[len++]=(*(p+i))[j];
		}
	}
}

int main(){
	char *a[]={"The program","is about m","any strings to"," be connected!"};
	char str[200];
	fun(str,a,4);
	printf("%s\n",str);
	return 0;
} 
