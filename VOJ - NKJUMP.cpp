#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1005;
int n; set<int> number;
int arr[MAX], dp[MAX];

bool binsearch(int value, int position) {
	if (arr[position] == value) {
		return (arr[position - 1] == value && position > 1) || (arr[position + 1] == value && position < n);
	}
	int l = 1; 
	int r = position;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (arr[mid] == value) {
			return true;
		}
		if (arr[mid] < value) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return false;
}

signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int res = 0;
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (binsearch(arr[i] - arr[j], j)) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += 1;
		res = max(res, dp[i]);
	}
	cout << res;
}
