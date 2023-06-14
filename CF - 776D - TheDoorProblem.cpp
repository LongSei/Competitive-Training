#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n, m, a[MAX];
vector<int> sw[MAX];
vector<int> adjlist[MAX];
int scc[MAX]; bool visited[MAX];

void dfs(int pos, int id) {
    scc[pos] = id;
    visited[pos] = true;
    for (int v : adjlist[pos]) {
        if (visited[v] == true) {
            continue;
        }
        dfs(v, id);
    }
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j++) {
            int v; cin >> v;
            sw[v].emplace_back(i);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        int u = sw[i][0];
        int v = sw[i][1];
		if (!a[i]) {
			adjlist[u].emplace_back(v + m);
			adjlist[v + m].emplace_back(u);
			adjlist[v].emplace_back(u + m);
			adjlist[u + m].emplace_back(v);
		} 
        else {
			adjlist[u].emplace_back(v);
			adjlist[v].emplace_back(u);
			adjlist[u + m].emplace_back(v + m);
			adjlist[v + m].emplace_back(u + m);
		}
    }
    int timer = 0;
    for (int i = 1; i <= 2 * m; i++) {
        if (visited[i] == false) {
            dfs(i, ++timer);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (scc[i] == scc[i + m]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

signed main() {
    faster;
    input();
    solve();
}
