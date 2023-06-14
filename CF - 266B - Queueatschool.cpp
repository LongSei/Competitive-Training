#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, t;
bool checkboy[51];
vector<int> pos;
char s[51];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == 'B') {
            checkboy[i] = true;
            pos.push_back(i);
        }
    }
    while (t--) {
        for (int i = 0 ; i < pos.size(); i++) {
            if (checkboy[pos[i] + 1] == false && pos[i] + 1 <= n) {
                checkboy[pos[i]] = false;
                checkboy[pos[i] + 1] = true;
                pos[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (checkboy[i] == true) {
            cout << 'B';
        }
        else {
            cout << 'G';
        }
    }
}