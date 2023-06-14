#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 1;
int n, q, arr[MAX], cnt[3], a, b;

signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	while (q--) {
		cin >> a >> b;
		if (a == 1) {
			cnt[arr[b]]--;
			arr[b] = 1 - arr[b];
			cnt[arr[b]]++;
		}
		if (a == 2) {
			if (b <= cnt[1]) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
 	}
}