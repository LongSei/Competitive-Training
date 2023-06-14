#include<bits/stdc++.h>
using namespace std;
#define int long long
int test;
string s;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> test;
    while (test--) {
        cin >> s;
        if (s.size() > 10) {
            cout << s[0] << (s.size() - 2) << s[s.size() - 1] << endl;
        }
        else {
            cout << s << endl;
        }
    }
}
