#include <iostream> 

using namespace std; 

  

int main() 

{ 

    int N; 

    cin>>N; 

    string s; 

    int circle; 

    for ( int i=0;i<N;i++) 

    { 

        cin>>s; 

        int len=s.length(); 

        for (circle=1;circle<= len;circle++) 

        {  

            bool flag=true; 

            int times= len/circle; 

            for( int num=0;num<circle; num++) 

            { 

                for( int j=1;j<=times;j++) 

                { 

                    if(s[ num]!=s[ num+circle*j]) {flag=false;} 

                } 

            } 

            if(flag==true && len%circle!=0) 

            { 

                for( int j=0;j<len%circle;j++) 

                { 

                    if(s[j]!=s[times*circle+j]) {flag=false;} 

                } 

            } 

            if(flag==true) break; 

        } 

        if(i) cout << endl; 

        cout<<circle<<endl; 

    } 

    return 0; 

} 