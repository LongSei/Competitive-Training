#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX = 2e5 + 100;
int dp[MAX];
int cnt[MAX];
int t, n, x, maxi, ans;

signed main() {
	cin >> n;
	memset(dp, 0, sizeof dp);
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i < MAX; i++) {
		dp[i] += cnt[i];
		for (int j = 2 * i; j < MAX; j += i) {
			dp[j] = max(dp[j], dp[i]);
		}
	}
	cout << *max_element(dp, dp + MAX) << endl;
}
