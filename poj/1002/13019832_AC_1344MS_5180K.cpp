#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
char convert(char c){
         if(c <= 'C') return '2';
         else if(c <= 'F') return '3';
         else if(c <= 'I') return '4';
         else if(c <= 'L') return '5';
         else if(c <= 'O') return '6';
         else if(c <= 'S') return '7';
         else if(c <= 'V') return '8';
         else if(c <= 'Y') return '9';
}
int main()
{
    int N;
    bool flag = false;
    cin >> N;
    map<string,int> telp_count;
    while(N--){
        string s,res;
        cin >> s;
        int i = 0;
       for(string::iterator s_it = s.begin();s_it != s.end();++s_it){
             if(*s_it >= '0' && *s_it <= '9') res.push_back(*s_it);
             if(*s_it >= 'A' && *s_it <= 'Z') res.push_back(convert(*s_it));
        }
        res.insert(3,1,'-');
        ++telp_count[res];
    }
    map<string,int>::iterator map_it = telp_count.begin();
    for(;map_it != telp_count.end();++map_it)
        if(map_it->second >= 2){
            flag = true;
            cout << map_it->first << " " << map_it->second << endl;
        }
    if(!flag)
        cout << "No duplicates." << endl;
    return 0;
}