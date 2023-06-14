#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
	int n; string s; cin >> n >> s;
    int res = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') continue;
        if (i < (int)n - 1) res++;
        res += s[i] - '0';
    }
    cout << res << '\n';
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}
