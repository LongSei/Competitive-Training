#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MAX 1001
int k, n, m, ans = 0;
int a[MAX][MAX], f[MAX][MAX];

signed main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
		}
	}
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			a[i][j] = f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k];
			if (ans < a[i][j]) {
				ans = a[i][j];
			}
		}
	}
	cout << ans;
}
