#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX=2e5 + 5;
const int MARR = 1e5;
const int INF = 1e8;
int n, l, s, arr[MAX], smin[MAX][51], smax[MAX][51];
int dp[MAX], lg[MAX];

int trvc(int l, int r) {
	int j = 0;
	while((1<<j+1)<=r-l+1) j++;
	int maxi = max(smax[l][j],smax[r-(1<<j)+1][j]);
	int mini = min(smin[l][j],smin[r-(1<<j)+1][j]);
	return maxi - mini;
}

signed main() {
	faster;
	cin >> n >> s >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		smin[i][0] = arr[i];
		smax[i][0] = arr[i];
	}
    for (int j = 1; (1 << j) <= n; j++) {
    	for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        	smin[i][j] = min(smin[i][j - 1],smin[i + (1 << (j - 1))][j - 1]);
			smax[i][j] = max(smax[i][j - 1],smax[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}
	int b = 0;
	dp[0] = 0;
	for (int i = l; i <= n; i++) {
		while (i - b >= l && (trvc(b + 1, i) > s || dp[b] >= INF)) {++b;}
		if (i - b >= l) {dp[i] = dp[b] + 1;}
	}
	if (dp[n] == INF) {
		cout << -1;
	}
	else {
		cout << dp[n];
	}
}
