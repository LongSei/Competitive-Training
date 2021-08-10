#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<int, int> ii;
const int INF = 1e12 + 7;
const int MAX = 5005;
int dist[MAX], n, m, timer[MAX];
vector<ii> adjlist[MAX];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int type, u, v, w;
		cin >> type >> u >> v >> w;
		if (type == 1) {
			adjlist[u].emplace_back(ii(w, v));
		}
		else {
			adjlist[u].emplace_back(ii(w, v));
			adjlist[v].emplace_back(ii(w, u));
		}
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

void dij() {
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	dist[1] = 0;
	timer[1] = 1;
	pq.push(ii(1, 0));
	while (pq.empty() == false) {
		ii nw = pq.top();
		pq.pop();
		int u = nw.first;
		int du = nw.second;
		if (du != dist[u]) {
			continue;
		}
		for (ii to : adjlist[u]) {
			int v = to.second;
			int dv = to.first;
			if (dist[v] < dist[u] + dv) {
				continue;
			}
			if (dist[v] > dist[u] + dv) {
				dist[v] = dist[u] + dv;
				timer[v] = timer[u];
				pq.push(ii(v, dist[v]));
			}
			else {
				timer[v] += timer[u];
			}
		}
	}
}

void solve() {
	dij();
	cout << dist[n] << " " << timer[n];
}

signed main() {
	faster;
	input();
	solve();
}
