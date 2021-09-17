#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 100005;
int n, m, dist[MAX];
int adjlist[MAX][2];

signed main() {
	faster;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> w >> u >> v;
		adjlist[w][0] = u;
		adjlist[w][1] = v;
	}
	queue<ii> q;
	q.push(ii(1, 1));
	dist[1] = 1;
	while (q.empty() == false) {
		ii nw = q.front(); q.pop();
		if (adjlist[nw.first][0]) {
			dist[adjlist[nw.first][0]] = dist[nw.first] + 1;
			dist[adjlist[nw.first][1]] = dist[nw.first] + 1;
			q.push(ii(adjlist[nw.first][0], dist[nw.first] + 1));
			q.push(ii(adjlist[nw.first][1], dist[nw.first] + 1));
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << endl;
	}
}
