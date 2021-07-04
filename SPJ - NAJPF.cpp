#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10000001;
int kmp[N];
int ans = 0;
string s, a, b;
int t;

signed main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		s = b + '#' + a;
		kmp[0] = 0;
		for (int i = 1; i <= s.size() - 1; i++) {
			int j = kmp[i - 1];
			while (j > 0 && s[j] != s[i]) {
				j = kmp[j - 1];
			}
			if (s[i] == s[j]) {
				j++;
			}
			kmp[i] = j;
			if (kmp[i] == b.size()) {
				ans++;
			}
		}
		if (ans == 0) {
			cout << "Not Found";
		}
		else {
			cout << ans << endl;
			for (int i = 1; i <= s.size() - 1; i++) {
				if (kmp[i] == b.size()) {
					cout << i - 2 * b.size() + 1 << " ";
				}
			}
		}
		cout << endl;
		cout << endl;
		ans = 0;
	}
}
