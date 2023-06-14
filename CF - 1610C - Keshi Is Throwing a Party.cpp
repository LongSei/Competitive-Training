#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5 + 5;
int test, n;
pair<int, int> ab[MAX];

bool isok(int total) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (total - 1 - ab[i].first <= sum && sum <= ab[i].second) {
			sum++;
		}
	}
	return sum >= total;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ab[i].first >> ab[i].second;
	}
	int ans = 0;
	int left = 1, right = n;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (isok(mid)) {left = mid + 1; ans = mid;}
		else {right = mid - 1;}
	}
	cout << ans << endl;
}

signed main() {
	cin >> test;
	while (test--) {
		solve();
	}
}
