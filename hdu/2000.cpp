#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
        char str[4];
        int i;
        while (cin >> str) {
                sort(str, str+3);
                for (i = 0; i < 2; i++)
                        cout << str[i] << " ";
                cout << str[i] << endl;
        }
        return 0;
}
