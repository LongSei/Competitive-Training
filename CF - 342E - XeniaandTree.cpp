#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
const int INF = 1e15 + 7;
int n, m, siz[MAX], in[MAX], out[MAX], up[MAX][30], timer = 0, depth[MAX], par[MAX];
vector<int> adjlist[MAX];
vector<int> centroid_adjlist[MAX];
int best_dist[MAX];
bool visited[MAX];

void dfs(int pos, int parent) {
    in[pos] = ++timer;
    up[pos][0] = parent;
    for (int i = 1; i <= 19; i++) {
        up[pos][i] = up[up[pos][i - 1]][i - 1];
    }
    for (int v : adjlist[pos]) {
        if (v != parent) {
            depth[v] = depth[pos] + 1;
            best_dist[v] = best_dist[pos] + 1;
            dfs(v, pos);
        }
    }
    out[pos] = timer;
}

bool is_ances(int u, int v) {
    return (in[u] <= in[v] && out[u] >= out[v]);
}

int lca(int u, int v) {
    if (is_ances(u, v) == true) {
        return u;
    }
    if (is_ances(v, u) == true) {
        return v;
    }
    for (int i = 19; i >= 0; i--) {
        if (is_ances(up[u][i], v) == false) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int dist(int u, int v) {
    int p = lca(u, v);
    return depth[v] + depth[u] - (2 * depth[p]);
}

void getsiz(int pos, int parent) {
    siz[pos] = 1;
    for (int v : adjlist[pos]) {
        if (v != parent && visited[v] == false) {
            getsiz(v, pos);
            siz[pos] += siz[v];
        }
    }
}

int find_centroid(int pos, int parent, int n) {
    for (int v : adjlist[pos]) {
        if (visited[v] == false && v != parent && siz[v] > n / 2) {
            return find_centroid(v, pos, n);
        }
    }
    return pos;
}

void decompose(int pos, int parent) {
    getsiz(pos, parent);
    int cent = find_centroid(pos, -1, siz[pos]);
    par[cent] = parent;
    centroid_adjlist[parent].emplace_back(pos);
    visited[cent] = true;
    for (int v : adjlist[cent]) {
        if (visited[v] == false && v != parent) {
            decompose(v, cent);
        }
    }
}

void update(int pos) {
    int nw = pos;
    while (nw != 0) {
        best_dist[nw] = min(best_dist[nw], dist(pos, nw));
        nw = par[nw];
    }
}

int query(int pos) {
    int nw = pos;
    int res = INF;
    while (nw != 0) {
        res = min(res, best_dist[nw] + dist(nw, pos));
        nw = par[nw];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adjlist[v].emplace_back(u);
        adjlist[u].emplace_back(v);
    }
    dfs(1, 1);
    decompose(1, 0);
    for (int i = 1; i <= m; i++) {
        int type, node; cin >> type >> node;
        if (type == 1) {
            update(node);
        }
        else {
            cout << query(node) << endl;
        }
    }
}

signed main() {
    faster;
    solve();
}
