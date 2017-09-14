#include <bits/stdc++.h>

using namespace std;

string a,s;
int f[1111];

void getfill(string s)
{
    memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<s.size();i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}

int find(string a,string s)
{
    
    getfill(s);int j=0;
    for(int i=0;i<a.size();i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==s.size()){
            return i-s.size()+1;
        }
    }
}

int main(){
	cin>>s>>a;
	int t=find(a,s); 
	printf("%d\n",t);
	return 0;
}

/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
#include <string>
using namespace std;
int f[ 15000];
void getfill(string s)
{
    memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<s.size();i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}
int find(string a,string s)
{
    int ans=0;
    getfill(s);int j=0;
    for(int i=0;i<a.size();i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==s.size()){
            ans++;
        }
    }
    return ans;
}
int main()
{
    string s,a;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        getchar();
        cin>>s>>a;
        int ans=find(a,s);
        printf("%d\n",ans);
    }
    return 0;
}
*/
