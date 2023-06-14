#include<bits/stdc++.h>
using namespace std;
int n;
int x;
long long cnt[100001] = {0};
int ans = 0;
int maex = 0;

int main() {
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		cnt[x]++;
		if (x > maex) {
			maex = x;
		}
	}
	long long dp[100001];
	dp[0] = 0;
	dp[1] = cnt[1];
	for (int i = 1 ;i <= maex; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + (i * cnt[i]));
	}
	cout << dp[maex];
}
