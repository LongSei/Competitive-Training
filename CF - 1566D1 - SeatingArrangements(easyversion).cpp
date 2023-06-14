#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 305;
int n, arr[MAX];

signed main() {
	faster;
	int test;cin >> test;
	while (test--) {
		int m; cin >> m >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (arr[i] > arr[j]) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
