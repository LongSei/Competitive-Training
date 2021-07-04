#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 1;
int st, en, ans = 0;

int solve(int k) {
	if (k == 1) {
		return 0;
	}
	int sum = 1;
	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0) {
			sum += i;
			if (k / i != i) {
				sum += k / i;
			}
		}
	}
	//cout << "I: " << k << " SUM: " << sum << endl;
	return sum;
}

signed main() {
	cin >> st >> en;
	for (int i = st; i <= en; i++) {
		if (solve(i) > i) {
			ans ++;
		}
	}
	cout << ans;
}
