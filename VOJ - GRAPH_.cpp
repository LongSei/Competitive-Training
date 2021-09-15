#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 10005;
int n, m; vector<int> adjlist[MAX];
bool criticalnode[MAX]; int low[MAX], num[MAX], timer = 0;
int CNode = 0, CEdge = 0;

void tarjan(int pos, int parent) {
	num[pos] = low[pos] = ++timer;
	int child = 0;
	for (int v : adjlist[pos]) {
		if (v != parent) {
			if (num[v]) {
				low[pos] = min(low[pos], num[v]);
			}
			else {
				tarjan(v, pos);
				low[pos] = min(low[pos], low[v]);
				child++;
				if (low[v] >= num[v]) {
					CEdge++;
				}
				if (pos == parent) {
					if (child >= 2) {
						criticalnode[pos] = true;
					}
				}
				else {
					if (low[v] >= num[pos]) {
						criticalnode[pos] = true;
					}
				}
			}
		}
	}
}

signed main() {
	faster;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adjlist[u].emplace_back(v);
		adjlist[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) {
			tarjan(i, i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (criticalnode[i] == true) {
			CNode++;
		}
	}
	cout << CNode << " " << CEdge;
}
