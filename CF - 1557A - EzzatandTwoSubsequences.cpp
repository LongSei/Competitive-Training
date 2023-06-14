#include<bits/stdc++.h>
using namespace std;
#define real long double
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 1e5 + 5;
const int INF = 1e18 + 7;
int n, arr[MAX], prefix[MAX];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		prefix[i] = arr[i] + prefix[i - 1];
	}
	real ans = -INF;
	for (int i = 1; i <= n - 1; i++) {
		real nw = (real)prefix[i] / (real)i + (real)(prefix[n] - prefix[i]) / (real)(n - i);
		ans = max(ans, nw);
	}
	cout << fixed << setprecision(6) << ans << endl;
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}
