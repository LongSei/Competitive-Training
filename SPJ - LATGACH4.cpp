#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 111539786;

struct mat {
	int x, y;
	int a[4][4];
};
mat operator * (mat a, mat b) {
	mat c;
	c.x = a.x;
	c.y = b.y;
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			c.a[i][j] = 0ll;
		}
	}
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			for (int k = 1; k <= c.x; k++) {
				c.a[i][j] = (c.a[i][j] + (a.a[i][k] * b.a[k][j] % mod)) % mod;
			}
		}
	}
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) {
		return a;
	}
	mat ans = Power(a, x / 2);
	if (x % 2 != 0) {
		return ans * ans * a;
	}
	return ans * ans;
}

mat a, x;
int t, n;
void build() {
	a.x = 2;
	a.y = 1;
	a.a[1][1] = 2;
	a.a[2][1] = 1;
	x.x = x.y = 2;
	x.a[1][1] = x.a[2][1] = x.a[1][2] = 1;
}

signed main() {
	cin >> t;
	build();
	while (t--) {
		cin >> n;
		if (n <= 2) {
			cout << n << endl;
			continue;
		}
		mat ans = Power(x,n-2) * a;
		cout << ans.a[1][1] << endl;
	}
}
