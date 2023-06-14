#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ep emplace_back
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int n, query;
int depth[MAX], up[MAX][18], in[MAX], out[MAX], timer = 0;
vector<int> adjlist[MAX];

void dfs(int pos, int parent) {
	in[pos] = ++timer;
	up[pos][0] = parent;
	for (int i = 1; i <= 17; i++) {
		up[pos][i] = up[up[pos][i - 1]][i - 1];
	}
	for (int v : adjlist[pos]) {
		if (v != parent) {
			depth[v] = depth[pos] + 1;
			dfs(v, pos);
		}
	}
	out[pos] = timer;
}

bool isancestor(int u, int v) {
	if (in[u] <= in[v] && out[u] >= out[v]) {
		return true;
	}
	return false;
}

int LCA(int u, int v) {
	if (isancestor(u, v)) {
		return u;
	}
	if (isancestor(v, u)) {
		return v;
	}
	for (int i = 17; i >= 0; i--) {
		if (!isancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int dist(int u, int v) {
	int p = LCA(u, v);
	return depth[u] + depth[v] - (2 * depth[p]);
}

void input() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].ep(v);
		adjlist[v].ep(u);
	}
	cin >> query;
}

bool checking(int dist1, int dist2) {
	if (dist1 <= dist2 && (dist2 - dist1) % 2 == 0) {
		return true;
	}
	return false;
}

void solve() {
	dfs(1, 1);
	for (int i = 1; i <= query; i++) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int d = dist(a, b);
		if (checking(d, k) == true) {
			cout << "YES" << endl;
		}
		else {
			int d1 = dist(x, a) + dist(y, b) + 1;
			int d2 = dist(y, a) + dist(x, b) + 1;
			if (checking(d1, k) == true || checking(d2, k) == true) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}

signed main() {
	faster;
	input();
	solve();
}