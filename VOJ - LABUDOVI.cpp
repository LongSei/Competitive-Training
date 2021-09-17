#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int> 
const int MAX = 1505;
char board[MAX][MAX];
int n, m, depth[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int dist[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
vector<ii> swan;
bool isok(int nx, int ny) {
	return (nx >= 1 && nx <= n && ny >= 1 && ny <= m);
}

queue<ii> q;
signed main() {
	faster;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				swan.push_back(ii(i, j));
			}
		}
	}
	memset(depth, 1e9 + 7, sizeof(depth));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '.' || board[i][j] == 'L') {
				depth[i][j] = 0;
				q.push(ii(i, j));
			}
		}
	}
	while (q.empty() == false) {
		ii node = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (isok(nx, ny) && depth[nx][ny] > depth[node.first][node.second] + 1) {
				depth[nx][ny] = depth[node.first][node.second] + 1;
				q.push(ii(nx, ny));
			}
		}
	}
	for (int i= 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = depth[i][j];
		}
	}
	dp[swan[0].first][swan[0].second] = 0;
	q.push(ii(swan[0].first, swan[0].second));
	visited[swan[0].first][swan[0].second] = true;
	while (q.empty() == false) {
		ii nw = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nw.first + dx[i];
			int ny = nw.second + dy[i];
			if (isok(nx, ny) == true) {
				if (visited[nx][ny] == false || max(dp[nw.first][nw.second], depth[nx][ny]) < dp[nx][ny]) {
					dp[nx][ny] = max(dp[nw.first][nw.second], depth[nx][ny]);
					visited[nx][ny] = true;
					q.push(ii(nx, ny));
				}
			}
		}
	}
	cout << dp[swan[1].first][swan[1].second];
}
