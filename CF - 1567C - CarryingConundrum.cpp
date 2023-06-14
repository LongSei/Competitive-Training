#include <bits/stdc++.h>
using namespace std;
int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		int n, k, x, sum = 0, a = 0, b = 0;
		string s;
		cin >> s;
		n = s.size();
		for (int i = 0; i < n; i++) {
			if (i & 1)
				a = a * 10 + (s[i] - '0');
			else
				b = b * 10 + (s[i] - '0');
		}
		int ans = a * b + a + b - 1;
		cout << ans << endl;
	}
}
