#include<iostream>
using namespace std;

const double pi=3.141592654;

int main(void)
{
	int test;
	cin>>test;
	for(int t=1;t<=test;t++)
	{
		double x,y;
		cin>>x>>y;

		double Area=pi*(x*x+y*y);
		int RestYear=(int)(Area/100.0+1.0);
		cout<<"Property "<<t<<": This property will begin eroding in year "<<RestYear<<'.'<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}