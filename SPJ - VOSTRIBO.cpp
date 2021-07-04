#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
const int mod = 1e15 + 7;

struct mat {
	int x, y;
	int a[5][5];
};

ll solve(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	string X = "", Y = "", Z;
	for (; x>0; x/=10) X = X + char(x%10+'0');
	for (; y>0; y/=10) Y = Y + char(y%10+'0');
	Z.resize(X.size()+Y.size(),'0');
	FOR(i,0,X.size()-1) {
		int c = 0;
		FOR(j,0,Y.size()-1) {
			c += (Z[i+j]-'0') + (X[i]-'0')*(Y[j]-'0');
			Z[i+j] = char(c%10+'0');
			c /= 10;
		}
		if (c > 0) Z[i+Y.size()] += c;
	}
	ll ans = 0;
	FOD(i,Z.size()-1,0) ans = (ans*10ll + Z[i]-'0') % mod;
	return ans;
}

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
				c.a[i][j] = (c.a[i][j] + solve(a.a[i][k]%mod, b.a[k][j]%mod)) % mod;
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

mat a, b;
int t, n;

void build() {
	a.x = 4;
	a.y = 1;
	b.x = 4;
	b.y = 4;
	a.a[4][1] = 6;
	a.a[1][1] = 1;
	a.a[2][1] = 2;
	a.a[3][1] = 3;
	b.a[1][2] = b.a[2][3] = b.a[3][1] = b.a[3][2] = b.a[3][3] = 1;
	for (int i = 1; i <= 4; i++) {
		b.a[4][i] = 1;
	}
}

signed main() {
	cin >> t;
	build();
	while (t--) {
		cin >> n;
		if (n <= 3) {
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += i;
			}
			cout << sum << endl;
			continue;
		}
		mat ans = Power(b,n-3) * a;
		cout << ans.a[4][1] << endl;
	}
}
