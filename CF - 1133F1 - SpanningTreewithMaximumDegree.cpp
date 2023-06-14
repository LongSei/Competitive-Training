#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
const int MAX = 2e5 + 5;
typedef pair<int, int> ii;
int pset[MAX]; int n, m;
vector<int> adjlist[MAX];
bool check[MAX]; int deg[MAX];
vector<ii> edge;

void dfs(int pos) {
    check[pos] = true;
    for (auto v : adjlist[pos]) {
        if (check[v] == false) {
            edge.push_back(ii(v, pos));
            dfs(v);
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
        deg[u]++;
        deg[v]++;
    }
    int to_bfs = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[to_bfs] < deg[i]) {
            to_bfs = i;
        }
    }
    check[to_bfs] = true;
    for (int v : adjlist[to_bfs]) {
        edge.push_back(ii(to_bfs, v));
        check[v] = true;
    }
    for (auto v : adjlist[to_bfs]) {
        dfs(v);
    }
    for (ii v : edge) {
        cout << v.first << " " << v.second << endl;
    }
}
