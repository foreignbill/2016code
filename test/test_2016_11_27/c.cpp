#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void solve() {
    string s1;
    s1.resize(2 * s.size() + 2);
    s1[0] = '$';
    s1[1] = '#';
    for (int i = 0; i < s.size(); ++i) {
        s1[(i + 1) << 1] = s[i];
        s1[((i + 1) << 1) + 1] = '#';
    }
    vector<int> p(s1.size(), 0);
    int res = 0;
    for (int id = 0, i = 1; i < s1.size(); ++i) {
        if (p[id] + id > i) p[i] = min(p[2 * id - i], p[id] + id - i);
        else p[i] = 1;
        while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
        if (i + p[i] > id + p[id]) id = i;
        res = max(res, p[i]);
    }
    cout << res - 1 << endl;
}

int main() {
    cin >> N;
    while (N--) {
        cin >> s;
        solve();
    }
    return 0;
}
