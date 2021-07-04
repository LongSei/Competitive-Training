#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000
int n, arr[105], f[22222], s;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int add = 0;
	if (s >= 20000) {
		add = (s - 20000) / arr[n - 1];
		s -= add * arr[n - 1];
	}
	for (int i = 1; i <= s; i++) {
		f[i] = INF;
		for (int j = 0; j < n && arr[j] <= i; j++) {
			f[i] = min(f[i], f[i - arr[j]] + 1);
		}
	}
	cout << f[s] + add;
	return 0;
}
