#include<bits/stdc++.h>
using namespace std;
#define real long double
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 1e5 + 5;
const int INF = 1e18 + 7;
int n, k, arr[MAX];
pair<int, int> brr[MAX];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		brr[i] = make_pair(arr[i], i);
	}
	sort(brr + 1, brr + 1 + n);
	int number = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (brr[i].second != (brr[i + 1].second - 1)) {
			number++;
		}
	}
	if (number <= k) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}
