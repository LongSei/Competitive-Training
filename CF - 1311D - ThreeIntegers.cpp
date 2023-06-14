#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 1e5;

signed main() {
	faster;
	int test; cin >> test;
	while (test--) {
		int a, b, c;
		cin >> a >> b >> c;
		int res[4];
		int ans = INT_MAX;
		for (int i = 1; i <= MAX; i++) {
			for (int j = i; j <= MAX; j += i) {
				for (int z = j; z <= MAX; z += j) {
					int total = abs(a - i) + abs(b - j) + abs(c - z);
					if (total < ans) {
						ans = total;
						res[1] = i;
						res[2] = j;
						res[3] = z;
					}
				}
			}
		}
		sort(res + 1, res + 1 + 3);
		cout << ans << endl;
		for (int i = 1; i <= 3; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
}
