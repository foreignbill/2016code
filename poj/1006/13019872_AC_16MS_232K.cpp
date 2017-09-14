#include<iostream>

using namespace std;

int main(){

int a,b,c,d,n = 1;

while (cin>>a>>b>>c>>d){

if(a==-1&&b==-1 && c==-1&&d==-1)break;

else{

int day=(5544*a+14421*b+1288*c-d+21252)%(23*28*33);

if(day<=0)

cout<<"Case "<<n++<<": the next triple peak occurs in "<<21252-d<<" days."<<endl;

else 

cout<<"Case "<<n++<<": the next triple peak occurs in "<<day<<" days."<<endl;

}

}

return 0;

}