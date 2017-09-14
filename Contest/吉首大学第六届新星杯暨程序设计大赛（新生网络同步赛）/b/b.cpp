#include<iostream>
#include<string>
using namespace std;
int N;
string M;
string fanxiang(string str){
	int i;
	char temp;
	int le=str.length();
	for(i=0;i<le/2;i++){
		temp=str[i];
		str[i]=str[le-i-1];
		str[le-i-1]=temp;
	}
	return str;
}
int ishuiwen(string str){
	int i;
	int len=str.length();
	char temp;
	for(i=0;i<len/2;i++){
		if (str[i]!=str[len-i-1])
			return false;
	}
	return true;
}
int char2int(char A){
	if (A>'9')
		return A-'A'+10;
	else
		return A-'0';
}
char int2char(int n){
	if (n>9)
		return n+'A'-10;
	else
		return n+'0';
}
string addAB(string A,string B)
{
	int lenA,lenB,i,j,temp=0,s;
	string AB="";
	lenA=A.length();
	lenB=B.length();
	i=lenA-1;
	j=lenB-1;
	while(1)
	{
		s=char2int(A[i])+char2int(B[j])+temp;
		if (s<N)
		{
			temp=0;
			AB=string(1,int2char(s))+AB;
		}
		else
		{
			temp=s/N;
			AB=string(1,int2char(s%N))+AB;
		}
		if (i==0&&j==0)
			break;
		if (i==0)
			A[i]='0';
		else
			i--;
		if (j==0)
			B[j]='0';
		else
			j--;
	}
	if (temp==0)
		return AB;
	else
		return string(1,int2char(temp))+AB;
}
void diedai(){
	string temp=M;
	int i,sp=0;
	for (i=0;i<30;i++){
		temp=addAB(M,fanxiang(M));
		if (ishuiwen(temp)){
			sp=1;
			break;
		}
		else
			M=temp;
	}
	if (sp==1)
		cout<<"STEP="<<i+1<<endl;
	else
		cout<<"Impossible!"<<endl;
}
int main()
{
	while(cin>>N>>M)
	{
		if(ishuiwen(M)) puts("STEP=0"); else
		diedai();
	}
	return 0;
}
