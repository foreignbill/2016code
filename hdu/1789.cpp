#include<bits/stdc++.h>
using namespace std;
struct HomeWork
{
    int deadline;
    int reduce;
}hw[1005];
bool mark[1005];
int t;int n;
int search(HomeWork a[],int x,int len)
{
    int i,pl=-1,min=x;
    for(i=0;i<len;i++)
        if(mark[i]==true&&a[i].reduce<min)
        {
            min=a[i].reduce;
            pl=i;
        }
        return pl;
}
bool cmp(HomeWork a ,HomeWork b)
{
    if(a.deadline!=b.deadline)
        return a.deadline<b.deadline;
    else
        return a.reduce>b.reduce;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        memset(hw,0,sizeof(hw));
        int i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&hw[i].deadline);
        for(i=0;i<n;i++)
            scanf("%d",&hw[i].reduce);
        sort(hw,hw+n,cmp);
   
        int day=0,reduced=0,tmp;
        for(i=0;i<n;i++)
        {
            if(day<hw[i].deadline)
            {
                day++;mark[i]=true;
            }
            else
            {
                int ex=search(hw,hw[i].reduce,i);
                if(ex!=-1)
                {
                    tmp=hw[ex].reduce;
                    hw[ex].reduce=hw[i].reduce;
                    hw[i].reduce=tmp;
                   
                }
           
                    reduced+=hw[i].reduce;
 
            }
        }
       
        printf("%d\n",reduced);
       
    }
    return 0;
}
