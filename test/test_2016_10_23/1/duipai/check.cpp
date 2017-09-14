#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d2.out","w",stdout);
	char s1[1000],s2[1000];
	cin>>s1>>s2;
	int po1=0,po2=0,po3=0,Max=0;
	int len1=strlen(s1),len2=strlen(s2);	
	for(po2=0;po2<len2;po2++)
	{
		int len=0;
		po3=po2;
		for(po1=0;po1<len1;po1++)
		{
			if(po3>=len2)
				break;
			if(s2[po3]==s1[po1])
			{
				len++;
				po3++;
			}
		}
		Max=max(Max,len);
	}
	cout<<Max<<endl;
	return 0;
}

