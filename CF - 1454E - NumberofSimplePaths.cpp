#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 2e5 + 5;
const int INF = 1e15 + 5;
int low[MAX], num[MAX], timer = 0, siz[MAX];
int test, n; vector<int> adjlist[MAX]; bool exist_cycle = false, iscycle[MAX];
stack<int> st; vector<int> incycle;

void reset(int n) {
	exist_cycle = false;
	st = stack<int>();
	incycle.clear();
	for (int i = 0; i <= n + 1; i++) {
		adjlist[i].clear();
		iscycle[i] = false;
		low[i] = 0;
		num[i] = 0;
		siz[i] = 0;
	}
	timer = 0;
}

void tarjan(int pos, int parent) {
	num[pos] = low[pos] = ++timer;
	st.push(pos);
	for (int v : adjlist[pos]) {
		if (num[v] && v != parent) {
			low[pos] = min(low[pos], num[v]);
		}
		else if (v != parent) {
			tarjan(v, pos);
			low[pos] = min(low[pos], low[v]);
		}
	}
	if (low[pos] == num[pos] && exist_cycle == false) {
		incycle.clear();
		int nw = 0;
		while (nw != pos) {
			nw = st.top(); st.pop();
			incycle.emplace_back(nw);
			low[nw] = num[nw] = INF;
		}
		if (incycle.size() > 1) {
			exist_cycle = true;
		}
	}
}

void dfs(int pos, int parent) {
	siz[pos] = 1;
	for (int v : adjlist[pos]) {
		if (v == parent || iscycle[v] == true) {
			continue;
		}
		dfs(v, pos);
		siz[pos] += siz[v];
	}
}

void solve() {
	cin >> n;
	reset(n);
	for (int i = 1; i <= n; i -= -1) {
		int u, v; cin >> u >> v;
		adjlist[u].emplace_back(v);
		adjlist[v].emplace_back(u);
	}
	tarjan(1, 0);
	for (int v : incycle) {
		iscycle[v] = true;
	}
	for (int v : incycle) {
		dfs(v, 0);
	}
	int ans = 0;
	int sub = 0;
	for (int v : incycle) {
		ans += siz[v] * (siz[v] - 1) / 2 + sub * siz[v] * 2;
		sub += siz[v];
	}
	cout << ans << endl;
}

signed main() {
	faster;
	cin >> test;
	while (test--) {
		solve();
	}
}
