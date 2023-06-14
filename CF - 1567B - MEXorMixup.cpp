#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int sav[300005];

signed main() {
	faster;
	for (int i = 1; i <= 300000; i++) {
		sav[i] = sav[i - 1] ^ i;
	}
	int test;
	cin >> test;
	while (test--) {
		int n, mex; cin >> mex >> n;
		if (mex == 0) {
			cout << 1 << endl;
			continue;
		}
		if (sav[mex - 1] == n) {
			cout << mex << endl;
			continue;
		}
		else {
			if ((sav[mex - 1] ^ n) == mex) {
				cout << mex + 2 << endl;
				continue;
			}
			else {
				cout << mex + 1 << endl;
				continue;
			}
		}
	}
}
