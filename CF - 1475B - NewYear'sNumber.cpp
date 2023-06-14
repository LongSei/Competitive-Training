#include<bits/stdc++.h>
using namespace std;
#define int long long
int test, n;

signed main() {
	cin >> test;
	while (test--) {
		cin >> n;
		int k = n % 2020;
		int d = (n - (n % 2020)) / 2020;
		if (k <= d) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
