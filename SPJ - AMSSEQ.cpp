#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int n, k, arr[MAX], dp[MAX], ans = 0;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = max(0, arr[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
		for (int j = i - k; j < i; j++) {
			dp[i] = max(dp[j] + arr[i], dp[i]);
		} 
	}
	for (int i = 1; i <= n; i++) {
		ans = max(dp[i], ans);
	}
	cout << ans;
}

