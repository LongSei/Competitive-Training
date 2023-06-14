#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		int a, b; cin >> a >> b;
		if (a == b) {
			cout << 0 << endl;
			continue;
		}
		if ((a % 2) != (b % 2)) {
			if (a < b) {
				cout << 1 << endl;
				continue;
			}
			else {
				cout << 2 << endl;
				continue;
			}
		}
		else {
			if (a > b) {
				cout << 1 << endl;
				continue;
			}
			else {
				cout << 2 << endl;
			}
		}
	}
}
