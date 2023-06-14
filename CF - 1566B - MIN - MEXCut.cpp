#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int arr[MAX], number[2];
signed main() {
	int test;
	cin >> test;
	while (test--) {
		string s; cin >> s;
		int cnt = 0;
		int nw = -1;
		number[0] = 0;
		number[1] = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - 48 != nw) {
				nw = s[i] - 48;
				arr[++cnt] = nw;
			}
		}
		for (int i = 1; i <= cnt; i++) {
			number[arr[i]]++;
		}
		if (number[0] == 0) {
			cout << 0 << endl;
			continue;
		}
		if (number[1] == 0) {
			cout << 1 << endl;
			continue;
		}
		if (number[0] >= 2) {
			cout << 2 << endl;
			continue;
		}
		else {
			cout << 1 << endl;
			continue;
		}
	}
}
