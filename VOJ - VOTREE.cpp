#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 3e5 + 5;
const int INF = 1e9 + 7;
int n, q, up[MAX][25], timer = 0, in[MAX], out[MAX];
int mark_in[2 * MAX], mark_out[2 * MAX];
vector<int> adjlist[MAX];
pair<int, int> ddat[MAX];

void dfs(int pos, int parent) {
	in[pos] = ++timer;
	up[pos][0] = parent;
	for (int i = 1; i <= 20; i++) {
		up[pos][i] = up[up[pos][i - 1]][i - 1];
	}
	for (int v : adjlist[pos]) {
		if (v != parent) {
			dfs(v, pos);
		}
	}
	out[pos] = ++timer;
}

bool ances(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
	if (ances(u, v)) {
		return u;
	}
	if (ances(v, u)) {
		return v;
	}
	for (int i = 20; i >= 0; i--) {
		if (!ances(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

void input() {
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].emplace_back(v);
		adjlist[v].emplace_back(u);
	}
	dfs(1,1);
}

pair<int, int> st[MAX * 4];

void build(pair<int, int> arr[], int v, int tl, int tr) {
	if (tl == tr) {
		st[v].first = arr[tl].first;
		st[v].second = arr[tl].second;
		return;
	}
	int mid = (tl + tr) >> 1;
	build(arr, v * 2 + 1, tl, mid);
	build(arr, v * 2 + 2, mid + 1, tr);
	st[v].first = min(st[v * 2 + 1].first, st[v * 2 + 2].first);
	st[v].second = max(st[v * 2 + 1].second, st[v * 2 + 2].second);
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
	if (tl > r || tr < l) {
		return pair<int, int>(INF, -INF);
	}
	if (l <= tl && tr <= r) {
		return st[v];
	}
	int mid = (tl + tr) >> 1;
	pair<int, int> left = query(v * 2 + 1, tl, mid, l, r);
	pair<int, int> right = query(v * 2 + 2, mid + 1, tr, l, r);
	return make_pair(min(left.first, right.first), max(left.second, right.second));
}

void solve() {
	for (int i = 1; i <= n; i++) {
		ddat[i] = pair<int, int>(in[i], out[i]); 
		mark_in[in[i]] = i;
		mark_out[out[i]] = i;
	}
	build(ddat,1,1,n);
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		pair<int, int> al = query(1,1,n,u,v);
		cout << lca(mark_in[al.first], mark_out[al.second]) << endl;
	}
}

signed main() {
	faster;
	input();
	solve();
}
