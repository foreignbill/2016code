#include<iostream>  
using namespace std;  
int n;                  
int counter;            //1计数，即“-”号计数         
int p[30][30];      
 
int cnt[30];
 
void DFS(int n)    
{  
    int i, j;          
    if( n > 24 )  
    {  
        return ;               
    }  
    else 
    {  
       for(i=0; i<2; ++i)  
       {  
            p[1][n] = i;        //第一行第n个符号  
            counter += i;       //“-”号统计,因为"+"的值是0 
              
            for(j=2; j<=n; ++j)  //当第一行符号>=2时，可以运算出下面行的某些符号，j可代表行号  
            {   
               p[j][n-j+1] = p[j-1][n-j+1]^p[j-1][n-j+2];//通过异或运算下行符号，t-j+1确定的很巧  
               counter += p[j][n-j+1];                       
            }   
			
			if(n*(n+1)/2==2*counter)
			{
				cnt[n]++;
			}
            
            DFS(n+1);        
            
			
            for(j=2; j<=n; ++j)    //回溯，判断另一种符号情况   像是出栈一样，恢复所有对counter的操作
            {  
                counter -= p[j][n-j+1];  
            }                   
            counter -= i;  
       }  
    }  
}  
 
int main()  
{ 
	counter = 0;

	DFS(1);
    while(cin >> n,n)
	{
		cout<<cnt[n]<<endl;
	} 
    return 0;  
}
   
