#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 5000;
int c, number, arr[17];
bool dp[MAX];

signed main() {
	cin >> c >> number;
	for (int i = 1; i <= number; i++) {
		cin >> arr[i];
	}
	dp[0] = true;
	for (int i = 1; i <= number; i++) {
		//cout << arr[i] << " ";
		for (int j = c; j >= arr[i]; j--) {
			if (dp[j - arr[i]] == true) {
				dp[j] = true;
		//		cout << j << " ";
			}
		}
		//cout << endl;
	}
	for (int i = c; i >= 0; i--) {
		if (dp[i] == true) {
			cout << i;
			return 0;
		}
	}
}
