#include<bits/stdc++.h>
using namespace std;
#define MAX 700
#define int long long
int n, m, board[MAX][MAX];
bool ishill = true;
bool visited[MAX][MAX];
int ans = 0;
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (ishill == true && board[nx][ny] > board[x][y]) {
				ishill = false;
			}
			if (board[nx][ny] == board[x][y] && visited[nx][ny] == false) {
				dfs(nx, ny);
			}
		} 
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m ; j++) {
			visited[i][j] = false;
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m; j++) {
			ishill = true;
			if (visited[i][j] == false) {
				dfs(i, j);
				if (ishill == true) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}
