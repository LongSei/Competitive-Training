#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int MAX = 10e4 + 1;
map<int, int> issquare;
int n, arr[MAX], dp[MAX], ans = 0;

void build() {
	for (int i = 1; i <= MAX; i++) {
		int k = i * (i + 1) / 2;
		issquare[k] = 1;
	}
}

signed main() {
	faster;
	build();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (issquare[arr[1]] == 1) {
		dp[1] = 1;
	}
	else {
		dp[1] = 0;
	}
	//cout << "DP" << 1 << ": " << dp[1] << endl;
	for (int i = 2; i <= n; i++) {
		if (issquare[arr[i]] == 1) {
			if (arr[i] >= arr[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = 1;
			}
		}
		else {
			dp[i] = 0;
		}
		//cout << "DP" << i << ": " << dp[i] << endl;
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans;
}
