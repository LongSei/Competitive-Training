#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'U') {
				cout << 'D';
			}
			else if (s[i] == 'D') {
				cout << 'U';
			}
			else {
				cout << s[i];
			}
		}
		cout << endl;
	}
}
