#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 3005;
int test, arr[MAX], dp[MAX][MAX], next_pos[MAX], save[MAX];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		next_pos[i] = save[arr[i]];
		save[arr[i]] = i;
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			dp[i][j] = 0;
		}
		save[i] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int tl = 1, tr = len; tr <= n; tl++, tr++) {
			dp[tl][tr] = min(dp[tl][tr - 1], dp[tl + 1][tr]) + 1;
			for (int j = next_pos[tr]; j >= tl; j = next_pos[j]) {
				dp[tl][tr] = min(dp[tl][tr], dp[tl][j] + dp[j + 1][tr]);
			}
		}
	}
	cout << dp[1][n] << endl;
}

signed main() {
	faster;
	cin >> test;
	while(test--) {
		solve();
	}
}
