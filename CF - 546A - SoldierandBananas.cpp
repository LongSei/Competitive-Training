#include <bits/stdc++.h>
using namespace std;
int k, n, w;
int sum = 0;
int main() {
	cin >> k >> n >> w;
	sum = k * (w * (w + 1) / 2);
	if (sum - n < 0) {
		cout << 0;
	}
	else {
		cout << sum - n;
	}
}
