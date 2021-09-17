#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>  
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 105;
char board[MAX][MAX]; ii beg, ed;
int n, m, dist[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool isok(int nx, int ny) {
	return (nx >= 1 && nx <= n && ny >= 1 && ny <= m && board[nx][ny] != '*');
}

signed main() {
	faster;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B') {
				beg = ii(i, j);
			}
			if (board[i][j] == 'C') {
				ed = ii(i, j);
			}
		}
	}
	queue<ii> q;
	memset(dist, 1e9 + 7, sizeof(dist));
	dist[beg.first][beg.second] = 0;
	q.push(ii(beg.first, beg.second));
	while (q.empty() == false) {
		ii nw = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + nw.first;
			int ny = dy[i] + nw.second;
			if (isok(nx, ny) && dist[nx][ny] > dist[nw.first][nw.second] + 1) {
				q.push(ii(nx, ny));
				dist[nx][ny] = dist[nw.first][nw.second] + 1;
			}
		}
	}
	cout << dist[ed.first][ed.second];
}
