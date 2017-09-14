/*
����������Ҫ���ʱ���ȹ��������ĸ�����
num = n / lnx;
numΪ������֣�Խ�����ԽС��ֻ�ǹ��ƣ����ڹ��������������С��
������Ч��ò�ƺܸߣ�����˵�����ﵽ������ʱ�䣨��֪�������Ǽ�=��=��
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
int n;
bool visit[10100000];
int prime[10000000];


void init_prim()
{
	memset(visit, true, sizeof(visit));
	int num = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (visit[i] == true)
		{
			num++;
			prime[num] = i;
		}
		for (int j = 1; ((j <= num) && (i * prime[j] <= n));  ++j)
		{
			visit[i * prime[j]] = false;
			if (i % prime[j] == 0) break; //�㾦֮��
		}
	}
}

int main()
{
	memset(prime, 0, sizeof(prime));
	int count = 0;
	cin>>n;
	init_prim();
	for(int i = 0; i <= n; ++i)
		if(prime[i])
		{
			cout<<prime[i]<<" ";
			count++;
		}
		cout<<endl;
		cout<<"��������Ϊ��"<<count<<endl;
}
