#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;

int main() {
	int n, w, elm;
	cin >> n >> w;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> elm;
		v.push_back(elm);
	}
	sort(v.begin(), v.end());
	int mx = v[n];
	int mn = v[0];
	double minn = min(mx * 1.0 / 2.0, mn * 1.0);
	double ans = min(w * 1.0, 3 * minn * n);
	cout << setprecision(9) << ans;
	return 0;
}
