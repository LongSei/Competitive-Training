#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 33;
int dp[MAX][MAX][2][2], n[MAX];
vector<int> bits;

signed main() {
	faster;
	int N, K;
	while (cin >> N >> K) {

		bits.clear();
		memset(dp, 0, sizeof(dp));
		memset(n, 0, sizeof(n));
		int timer = 0;
		while (N > 0) {
			bits.emplace_back(N % 2);
			N /= 2;
		}
		if (bits.size() == 0) {
			bits.emplace_back(0);
		}		
		if (K > bits.size()) {
			cout << 0 << endl;
			continue;
		}
		dp[0][0][0][0] = 1;
		for (int i = 1; i <= bits.size(); i++) {
			n[i] = bits[bits.size() - i];
		}
		for (int i = 0; i < bits.size(); i++) {
			for (int k = 0; k <= i; k++) {
				for (int lower = 0; lower <= 1; lower++) {
					for (int positive = 0; positive <= 1; positive++) {
						for (int next_pos = 0; next_pos <= 1; next_pos++) {
							if (lower == 0 && next_pos > n[i + 1]) {
								continue;
							}
							int nw_lower = (lower || next_pos < n[i + 1]); 
							int nw_positive = (positive || next_pos == 1);
							int k2 = k + (positive && next_pos == 0);
							dp[i + 1][k2][nw_lower][nw_positive] += dp[i][k][lower][positive];
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= 1; i++) {
			ans += dp[bits.size()][K][i][1];
		}
		if (K == 1) {
			ans++;
		}
		cout << ans << endl;
	}
}
