#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	int t, m;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), pref(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int mx = -1;
		for (int i = 0; i < n; i++) {
			pref[i] = max(mx, b[i]);
			mx = pref[i];
		}
		int mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(pref.begin(), pref.end(), a[i]) - pref.begin();
			mn = min(mn, it + i);
		}
		cout << mn << "\n";
	}
}
