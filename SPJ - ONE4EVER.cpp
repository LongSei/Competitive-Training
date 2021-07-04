#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 3
#define mod m
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
typedef unsigned long long ull;
typedef long long ll;
int h,b,m,k;

struct mat {
	int x,y;
	int m[N][N];
};

ull solve(ull x, ull y) {
	if (x == 0 || y == 0) return 0;
	string X = "", Y = "";
	for (; x>0; x/=10) X += char(x % 10 + '0');
	for (; y>0; y/=10) Y += char(y % 10 + '0');
	string Z(X.size() + Y.size(), '0');
	FOR(i,0,X.size()-1) {
		int c = 0;
		FOR(j,0,Y.size()-1) {
			int g = Z[i+j]-'0' + c + (X[i]-'0')*(Y[j]-'0');
			c = g/10;
			g %= 10;
			Z[i+j] = char(g + '0');
		}
		if (c > 0) Z[i+Y.size()] = char(Z[i+Y.size()]-'0'+c+'0');
	}
	ull ans = 0;
	FOD(i,Z.size()-1,0)
	ans = (ans*10ull + Z[i]-'0') % m;
	return ans;
}

mat operator * (mat a, mat b) {
	mat c;
	c.x = a.x;
	c.y = b.y;
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			c.m[i][j] = 0ll;
		}
	}
	for (int i = 1; i <= c.x; i++) {
		for (int j = 1; j <= c.y; j++) {
			for (int k = 1; k <= c.x; k++) {
				c.m[i][j] = (c.m[i][j] + solve(a.m[i][k]%m, b.m[k][j]%m)) % m;
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

mat a,x;

void build() {
	x.x = 2;
	x.y = 2;
	a.x = 2;
	a.y = 1;
	x.m[1][1] = h%m;
	x.m[1][2] = b%m;
	x.m[2][1] = 0;
	x.m[2][2] = 1;
	a.m[1][1] = b % m;
	a.m[2][1] = 1;
}

signed main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> h >> b >> m >> k;
		build();
		if (k == 1) {
			cout << b % m << endl;
			continue;
		}
		mat ans = Power(x, k - 1) * a;
		cout << ans.m[1][1] << endl;
	}
}
