#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
pair<int, int> arr[MAX];
int nsw[MAX];
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		char u; cin >> u;
		arr[i].first = u - '0';
	}
	for (int i = 1; i <= n; i++) {
		char u; cin >> u;
		arr[i].second = u - '0';
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i].first != arr[i].second) {
			ans += 2;
		}
		else {
			if (arr[i].first == 1) {
				if (arr[i + 1].first == 0 && arr[i + 1].second == 0 && i + 1 <= n) {
					ans += 2;
					i++;
				}
			}
			else {
				if (arr[i + 1].first == 1 && arr[i + 1].second == 1 && i + 1 <= n) {
					ans += 2;
					i++;
				}
				else {
					ans += 1;
				}
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}
