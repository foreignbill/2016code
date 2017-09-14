#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string> 
#include <cstring>

using namespace std;

void removeLastZero(char* numstr)  
{  
    if (NULL == strchr(numstr, '.'))  
        return;  
  
    int length = strlen(numstr);  
    for (int i = length - 1; i > 0; --i)  
    {  
        if ('\0' == numstr[i])  
        {  
            continue;  
        }  
        else if ('0' == numstr[i])  
        {  
            numstr[i] = '\0';  
        }  
        else if ('.' == numstr[i])// 小数点之后全为零  
        {  
            numstr[i] = '\0';  
            break;  
        }  
        else// 小数点后有非零数字  
        {  
            break;  
        }  
    }  
}  

int main(){
	int T,n,m,s;
	scanf("%d\n",&T);
	while(T--){
		char st[10];
		gets(st);
		m=(st[0]-'0')*10 + st[1]-'0';
		s=(st[3]-'0')*10 + st[4]-'0';
		m%=12;
		double ax1 = m * 30.0  + s * 0.5;
		double ax2 = s * 6.0;
		double ans = fabs(ax1-ax2);
		if(ans>180.0) ans = 360 - ans ;
		char str[320]; 
		sprintf(str, "%f", ans);  
		removeLastZero(str);  
		std::cout<<str<<std::endl;   
	}
	return 0;
}
