#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int prefix[MAX];
string s, t;

signed main() {
	faster;
	cin >> s >> t;
	prefix[0] = 0;
	for(int i = 1; i <= t.size() - 1; i++) {
		int j = prefix[i - 1];
		while (j > 0 && t[j] != t[i]) {
			j = prefix[j - 1];
		}
		if (t[i] == t[j]) {
			j++;
		}
		prefix[i] = j;
	}
	int ans = 0;
	int dp[s.size() + 1][t.size() + 1];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= s.size(); i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= t.size(); j++) {
			if (s[i - 1] != '?' && s[i - 1] != t[j - 1]) {
				continue;
			}
			if (dp[i - 1][j - 1] == -1) {
				continue;
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (j == t.size()));
		}
		for (int j = t.size(); j >= 1; j--) {
			dp[i][prefix[j - 1]] = max(dp[i][prefix[j - 1]], dp[i][j]);
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans;
}
