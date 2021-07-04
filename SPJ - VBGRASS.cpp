#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX = 101;
char board[MAX][MAX];
int n, m;
int ans = 0;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void ff(int x, int y) {
	board[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (board[nx][ny] == '#') {
				ff(nx, ny);
			} 
		}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			if (board[i][j] == '#') {
				ff(i, j);
				ans++;
			}
		}
	}
	cout << ans;
}
