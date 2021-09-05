#include<bits/stdc++.h>
using namespace std;
const int MAX = 2000005;
string a, b; int prefix[MAX];

signed main() {
    cin >> a >> b;
    string s = b + '#' + a;
    prefix[0] = 0;
    for (int i= 1; i < s.size(); i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        prefix[i] = j;
    }
    for (int i = b.size() + 1; i < s.size(); i++) {
        if (prefix[i] == b.size()) {
            cout << i - (2 * b.size()) + 1 << " ";
        }
    }
}
