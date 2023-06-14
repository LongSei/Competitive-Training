#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main() {
	int test;
	cin >> test;
	while (test--) {
		int n, s;
		cin >> n >> s;
		if (n == 1) {
			cout << s << endl;
			continue;
		}
		int pre = n % 2 == 0 ? (n / 2) - 1 : n / 2;
		n -= pre;
		int remain = (s - (s % n)) / n;
		cout << remain << endl;
	}
}
