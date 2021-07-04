#include<bits/stdc++.h>
using namespace std;
int n, gt[200000];

void build() {
	gt[1] = 1;
	int cnt = 1;
	for (int i = 2; i <= 447; i++) {
		cnt++;
		int k = i - 1;
		if ((gt[cnt - 1] / (i - 1)) % i == 0) {
			gt[cnt] = gt[cnt - 1] + i;
		}
		else {
			gt[cnt] = gt[cnt - 1] + ((gt[cnt - 1] / (i - 1)) % i);
		}
		while (k--) {
			cnt++;
			gt[cnt] = gt[cnt - 1] + i;
		}
	}
}

signed main() {
	build();
	cin >> n;
	cout << gt[n];
}
