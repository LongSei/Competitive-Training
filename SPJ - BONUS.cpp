#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
#define int long long
int n, m, k, ans = 0;
int board[MAX][MAX];
int f[MAX][MAX];
//int hv[MAX][MAX];

signed main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m ; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + board[i][j];
			//cout << "I:" << i << " J: " << j << " F: " << f[i][j] << endl;
		}
	}
	for (int i = k; i <= n; i++) {
		for(int j = k; j <= m; j++) {
			board[i][j] = f[i][j] - f[i][j - k] - f[i - k][j] + f[i - k][j - k];
			if (board[i][j] > ans) {
				ans = board[i][j];
			}
			//cout << "I:" << i << " J: " << j << " HV: " << hv[i][j] << endl;
		}
	}
	cout << ans;
}
