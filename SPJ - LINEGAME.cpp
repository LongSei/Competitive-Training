#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, tg, m1 = 0, m2 = 0, m3, ans = 0;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tg;
		m3 = m1;
		if (m1 < m2 + tg) {
			m1 = m2 + tg;
		}
		if (m2 < m3 - tg) {
			m2 = m3 - tg;
		}
	}
	if (m1 > ans) {
		ans = m1;
	}
	if (m2 > ans) {
		ans = m2;
	}
	cout << ans;
}
