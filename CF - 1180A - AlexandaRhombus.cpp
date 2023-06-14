#include<bits/stdc++.h>
using namespace std;

int number;
int dp(int x) {
	if (x == 1) {
		return 1;
	}
	return dp(x - 1) + (4 * (x - 1));
}

int main() {
	cin >> number;
	cout << dp(number);
}
