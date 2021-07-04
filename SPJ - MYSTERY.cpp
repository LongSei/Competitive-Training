#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e9 + 1;
const int mod = 20122007;
int n;

int pow(int n) {
	int result = 1;
	int cs = 3;
	while (n > 0) {
        if (n & 1) (result *= cs) %= mod;
        n >>= 1;
        (cs *= cs) %= mod;
	}
	return result - 1;
}

signed main() {
	cin >> n;
	int ans = 1;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			//cout << i << " ";
			ans *= pow(i);
			ans = ans % mod;
			if (n / i != i) {
			//	cout << n/i << " ";
				ans *= pow(n / i);
				ans = ans % mod;
			}
		}
	}
	//cout << endl;
	cout << ans;
}
