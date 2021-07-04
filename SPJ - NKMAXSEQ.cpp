#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 5e4 + 1;
int n, p, x, arr[MAX], ans = -1, a[MAX];

signed main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] - a[j] >= p) {
				//cout << "I: " << i << " J: " << j << endl;
				if (i - j > ans) {
					ans = i - j;
				} 
			}
		}
	}
	cout << ans;
}
