#include<iostream>
using namespace std;
void FeedBack(int x=1)
{
    cout<<"Yes!!!=_="<<endl;
    return;
}
void FeedBack(double &y)
{
    cout<<"I don't know..."<<endl;
    return;
}
void FeedBack(int x,int y=1)
{
	cout<<x<<" "<<y<<endl; 
    cout<<"No,never.233"<<endl;
    return;
}
int main()
{
    cout<<"Do you want to come again?"<<endl;
    const int a=0;
    int b=0;
    const double c=0.0;
    double d=0.0;
    FeedBack(a,b);//Êä³ö No,never.233
    FeedBack();//Êä³ö Yes!!!=_=
    FeedBack(d);//Êä³ö I don't know...
    return 0;
}

