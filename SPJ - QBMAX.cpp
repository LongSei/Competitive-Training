#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int INF = 100000;
int n,m;
int board[MAX + 1][MAX + 1];
int v[MAX + 1][MAX + 1];
int ans = -INF;
 
int main() {
	cin >> n >> m;
	for (int i = 0; i <= m; i++) {
		v[0][i] = v[n + 1][i] = -INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			v[i][j] = max(v[i - 1][j - 1], max(v[i][j - 1], v[i + 1][j - 1])) + board[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, v[i][m]);
	}
	cout << ans;
}
