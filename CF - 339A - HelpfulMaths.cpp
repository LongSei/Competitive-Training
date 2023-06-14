#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> inp;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            inp.push_back(1);
        }
        else if (s[i] == '2') {
            inp.push_back(2);
        }
        else if (s[i] == '3') {
            inp.push_back(3);
        }
    } 
    sort(inp.begin(), inp.end());
    // for (int i = 0 ; i < inp.size(); i++) {
    //     cout << inp[i] << " ";
    // }
    for (int i = 0 ; i < inp.size(); i++) {
        if (i == 0) {
            cout << inp[i];
        }
        else {
            cout << '+';
            cout << inp[i];
        }
    }
}
