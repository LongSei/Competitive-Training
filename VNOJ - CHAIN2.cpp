#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 250000;
int trie[MAX + 5][30], mask[MAX];
int n, cnt = 0, ans = 0;

void add(string s) {
    int nw = 0, len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (trie[nw][s[i]] == 0) {
            trie[nw][s[i]] = ++cnt;
        }
        nw = trie[nw][s[i]];
        len = max(mask[nw], len);
    }
    mask[nw] = len + 1;
    ans = max(len + 1, ans);
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; 
        cin >> s;
        add(s);
    }
    cout << ans;
}
