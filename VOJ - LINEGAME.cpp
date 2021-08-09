#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
int n, arr[MAX];

signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int maxi1 = 0, maxi2 = 0;
	for (int i = 1; i <= n; i++) {
		int nw_maxi1 = max(maxi1, maxi2 - arr[i]);
		int nw_maxi2 = max(maxi2, maxi1 + arr[i]);
		maxi1 = nw_maxi1;
		maxi2 = nw_maxi2;
	}
	cout << max(maxi1, maxi2);
}
