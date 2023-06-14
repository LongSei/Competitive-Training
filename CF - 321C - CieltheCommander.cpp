#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define real long double
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int depth[MAX], siz[MAX];
bool cent[MAX];
vector<int> adjlist[MAX];
vector<int> cent_adjlist[MAX];

void getsiz(int pos, int parent) {
	siz[pos] = 1;
	for (int v : adjlist[pos]) {
		if (v != parent && cent[v] == false) {
			getsiz(v, pos);
			siz[pos] += siz[v];
		}
	}
}

int findcentroid(int pos, int parent, int n) {
	for (int v : adjlist[pos]) {
		if (v != parent && cent[v] == false && siz[v] > n / 2) {
			return findcentroid(v, pos, n);
		}
	}
	return pos;
}

void built(int pos, int parent) {
	getsiz(pos, parent);
	int c = findcentroid(pos, parent, siz[pos]);
	cent[c] = true; depth[c] = depth[parent] + 1;
	cent_adjlist[parent].emplace_back(c);
	for (int v : adjlist[c]) {
		if (v != parent && cent[v] == false) {
			built(v, c);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adjlist[u].emplace_back(v);
		adjlist[v].emplace_back(u);
	}
	built(1, 0);
	int maxi = -1;
	for (int i = 1; i <= n; i++) {
		maxi = max(maxi, depth[i]);
	}
	if (maxi > 26) {
		cout << "Impossible";
		return;
	}
	for (int i = 1; i <= n; i++) {
		cout << char('A' + depth[i] - 1) << " ";
	}
}

signed main() {
	faster;
	solve();
}
