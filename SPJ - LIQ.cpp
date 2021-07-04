#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1001;
int number, arr[MAX], dp[MAX], ans = 0;

signed main() {
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= number; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		if (dp[i] > ans) {
			ans = dp[i];
		}
		//cout << "NUMBER: " << i << " GT: " << dp[i] << endl;
	}
	cout << ans;
}
