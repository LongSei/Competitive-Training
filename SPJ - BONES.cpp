#include<bits/stdc++.h>
using namespace std;
#define MAX 81
#define int long long
int s1, s2, s3;
int ans = 0, gt = 0;
int cnt[MAX];

signed main() {
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				cnt[i + j + k]++;
			}
		}
	}
	for (int i = 3; i <= s1 + s2 + s3; i++) {
		if (cnt[i] > gt) {
			gt = cnt[i];
			ans = i;
		}
	}
	cout << ans;
}
