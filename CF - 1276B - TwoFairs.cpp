#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int test, n, m, a, b;
vector<int> adjlist[MAX];
bool visited[3][MAX]; bool fid[MAX];
int cnt[3];

void reset(int n) {
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
		visited[2][i] = false;
		visited[1][i] = false;
		visited[0][i] = false;
		fid[i] = false;
	}
	cnt[0] = cnt[1] = cnt[2] = 0;
}

void bfs(int s, int t, bool vis[]) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
	}
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u == t) continue;
        for (auto v : adjlist[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
		}
    }
}

void solve() {
	cin >> n >> m >> a >> b; reset(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adjlist[u].emplace_back(v);
		adjlist[v].emplace_back(u);
	}
	bfs(a, b, visited[0]);
	bfs(b, a, visited[1]);
    for (int i = 1; i <= n; i++) {
		cnt[0] += (visited[0][i] && visited[1][i] == false);
		cnt[1] += (visited[1][i] && visited[0][i] == false);
	}
	cout << cnt[1] * cnt[0] << endl;
}

signed main() {
	faster;
	cin >> test;
	while (test--) {
		solve();
	}
}
