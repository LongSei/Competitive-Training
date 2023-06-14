#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int siz[MAX], n;
bool handoi[MAX];
vector<int> adjlist[MAX];
int total = 0, res = 0;

void dfs(int pos, int parent) {
	bool ok = true;
	for (int v : adjlist[pos]) {
		if (v != parent) {
			dfs(v, pos);
			if (handoi[v] == true) {
				continue;
			}
			ok = false;
			siz[pos]++;
		}
	}
	if (ok == true || pos == 1) {
		if (parent == 1) {
			total++;
		}
	}
	else {
		handoi[pos] = true;
		res += siz[pos] - 1;
	}
}

signed main() {
	faster;
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		for (int i = 1; i <= n - 1; i++) {
			int u, v; cin >> u >> v;
			adjlist[u].emplace_back(v);
			adjlist[v].emplace_back(u);
		}
		dfs(1, 0);
		cout << res + max(total, 1ll) << endl;
		res = 0, total = 0;
		for (int i = 1; i <= n; i++) {
			handoi[i] = false;
			adjlist[i].clear();
			siz[i] = 0;
		}
	}
}
