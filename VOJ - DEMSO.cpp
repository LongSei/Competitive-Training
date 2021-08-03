#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e9 + 7;
int A,B,D,K, n[30];
// (position, number_ugly, last_digit, lower, positive)
const int MAX = 30;
int dp[MAX][MAX][10][2][2];

int f(int N, int d, int k) {
	vector<int> digits;
	while (N) {
		digits.emplace_back(N % 10);
		N /= 10;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0] = 1;
	for (int i = 1; i <= digits.size(); i++) {
		n[i] = digits[digits.size() - i];
	}
	for (int i = 0; i < digits.size(); i++) {
		for (int bad = 0; bad <= i; bad++) {
			for (int last = 0; last <= 9; last++) {
				for (int lower = 0; lower <= 1; lower++) {
					for (int positive = 0; positive <= 1; positive++) {
						for (int next_pos = 0; next_pos <= 9; next_pos++) {
							if (lower == 0 && next_pos > n[i + 1]) {
								continue;
							}
							int bad2 = bad;
							if(positive && abs(last - next_pos) <= d) {
								bad2++;
							}
							int last2 = next_pos;
							int lower2 = lower || (next_pos < n[i + 1]);
							int positive2 = positive || next_pos > 0;
							dp[i + 1][bad2][last2][lower2][positive2] += 
							dp[i][bad][last][lower][positive];
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		for (int last = 0; last <= 9; last++) {
			ans += dp[digits.size()][i][last][1][1];
		}
	}
	return ans;
}

void solve() {
	cout << f(B + 1, D, K) - f(A, D, K) << endl;
}

signed main() {
	faster;
	cin >> A >> B >> D >> K;
	solve();
}
