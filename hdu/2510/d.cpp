#include<iostream>  
using namespace std;  
int n;                  
int counter;            //1����������-���ż���         
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
            p[1][n] = i;        //��һ�е�n������  
            counter += i;       //��-����ͳ��,��Ϊ"+"��ֵ��0 
              
            for(j=2; j<=n; ++j)  //����һ�з���>=2ʱ����������������е�ĳЩ���ţ�j�ɴ����к�  
            {   
               p[j][n-j+1] = p[j-1][n-j+1]^p[j-1][n-j+2];//ͨ������������з��ţ�t-j+1ȷ���ĺ���  
               counter += p[j][n-j+1];                       
            }   
			
			if(n*(n+1)/2==2*counter)
			{
				cnt[n]++;
			}
            
            DFS(n+1);        
            
			
            for(j=2; j<=n; ++j)    //���ݣ��ж���һ�ַ������   ���ǳ�ջһ�����ָ����ж�counter�Ĳ���
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
   
