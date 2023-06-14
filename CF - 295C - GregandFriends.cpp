#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod = 1e9 + 7;
int n, k, dp[205][55][55], nCk[55][55], cnt50, cnt100;

signed main() {
	faster;
	cin >> n >> k;
	for (int i = 0; i <= 50; i++) {
		nCk[i][0] = 1;
	}
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= i; j++) {
			nCk[i][j] = (nCk[i - 1][j] + nCk[i - 1][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 100) {
			cnt100++;
		}
		else {
			cnt50++;
		}
	}
	dp[0][cnt50][cnt100] = 1;
	for (int pos = 0; pos <= 4 * n + 1; pos++) {
		for (int in_pos_50 = 0; in_pos_50 <= cnt50; in_pos_50++) {
			for (int in_pos_100 = 0; in_pos_100 <= cnt100; in_pos_100++) {
				if (dp[pos][in_pos_50][in_pos_100] == 0) {
					continue;
				}
				for (int change_50 = 0; change_50 <= in_pos_50; change_50++) {
					for (int change_100 = 0; change_100 <= in_pos_100 && change_100 * 100 + change_50 * 50 <= k; change_100++) {
						if (change_50 == 0 && change_100 == 0) {continue;}
						dp[pos + 1][cnt50 - in_pos_50 + change_50][cnt100 - in_pos_100 + change_100] = (dp[pos + 1][cnt50 - in_pos_50 + change_50][cnt100 - in_pos_100 + change_100] + dp[pos][in_pos_50][in_pos_100] * nCk[in_pos_50][change_50] * nCk[in_pos_100][change_100] % mod) % mod;
					}
				}
			}
		}
		if (pos % 2 == 0 && dp[pos + 1][cnt50][cnt100]) {
			cout << pos + 1 << endl;
			cout << dp[pos + 1][cnt50][cnt100];
			return 0;
		}
	}
	cout << -1 << endl << 0;
}