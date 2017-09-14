#include <cstdio>
#include <cstring>
#include <iostream> 

using namespace std;

const int dy[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isyear(int year){
	if(year%4==0&&year%100!=0||year%400==0) 
	return 1;
	else 
	return 0;
}

int main(){
	int T,year,month,day,second;
	cin>>T;
	while(T--){
		scanf("%d-%d-%d %d",&year,&month,&day,&second);
		int t = second / 86400 ;
		while(t--){
			day++;
			if(isyear(year)){
				if(month==2&&day==30){
					month=3;
					day=1;
				}
				else if(month!=2&&day==dy[month]+1){
					month=month+1;
					day=1;
				}
			}
			else{
				if(day==dy[month]+1){
					month=month+1;
					day=1;
				}
			}
			if(month==13){
				year++;
				month=1;
			}
		}
		printf("%d-%02d-%02d\n",year,month,day);
	}
	
	return 0;
}
