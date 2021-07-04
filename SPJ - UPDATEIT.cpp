#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 10001;
int test, arr[MAX], prefix[MAX], a, b, c, que, update, n;

signed main() {
	cin >> test;
	while (test--) {
		memset(prefix, 0, sizeof(prefix));
		memset(arr, 0, sizeof(arr));
		cin >> n >> update;
		while (update--) {
			cin >> a >> b >> c;
			prefix[a] += c;
			prefix[b + 1] -= c;
		}
		for (int i = 0; i < n; i++) {
			prefix[i] += prefix[i - 1];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = arr[i] + prefix[i];
		}
		cin >> que;
		while (que--) {
			cin >> a;
			cout << arr[a] << endl;
		}
	}
}