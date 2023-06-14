#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
typedef pair<int, int> ii;
int pset[MAX], n, m, d;
vector<int> adjlist[MAX];
vector<pair<int, int> > ans;
vector<pair<int, int> > remain;

int findset(int a) {
	while (pset[a] > 0) a = pset[a];
	return a; 
}
 
void unionset(int a, int b) {
	if (pset[a] < pset[b]) {
		pset[b] += pset[a];
		pset[a] = b;
	}
	else {
		pset[a] += pset[b];
		pset[b] = a;
	}
}

void dfs(int pos, int parent) {
    for (int v : adjlist[pos]) {
        if (v == 1) {
            continue;
        }
        if (pset[v] == 0) {
            pset[v] = parent;
            ans.push_back(ii(v, pos));
            dfs(v, parent);
        }
        else {
            if (v < pos) {
                remain.push_back(ii(v, pos));
            }
        }
    }
}

void solve() {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adjlist[u].emplace_back(v);
        adjlist[v].emplace_back(u);
    }
    if (d > adjlist[1].size()) {
        cout << "NO";
        return;
    }
    pset[1] = -1;
    for (int v : adjlist[1]) {
        pset[v] = -1;
    }
    for (int v : adjlist[1]) {
        dfs(v, v);
    }
    int D = adjlist[1].size();
    for (auto v : remain) {
        if (D == d) {
            break;
        }
        int p1 = findset(v.first);
        int p2 = findset(v.second);
        if (p1 == p2) {
            continue;
        }
        unionset(p1, p2);
        ans.push_back(v);
        D--;
    }
    if (D != d) {
        cout << "NO";
        return;
    }
    cout << "YES" << endl;
    for (int v : adjlist[1]) {
        if (pset[v] < 0) {
            cout << 1 << " " << v << endl;
        }
    }
    for (ii v : ans) {
        cout << v.first << " " << v.second << endl;
    }
}

signed main() {
    faster;
    solve();
}
