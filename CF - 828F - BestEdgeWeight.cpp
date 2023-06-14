#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<int, int> ii;
const int MAX = 2e5 + 5;
const int INF = 1e9 + 7;
struct node {
    int u, v, w, index;
    bool operator < (node other) const
    {
        return w < other.w;
    }
};
// FOR DFS
int chain = 1, cnt = 0, head[MAX], inchain[MAX], pos_in_hld[MAX], depth[MAX], setsize[MAX], par[MAX];
// FOR SEGMENT TREE
int st[MAX * 4], lazy[MAX * 4];
// FOR LCA
int in[MAX], out[MAX], timer = 0;
int up[MAX][30], val[MAX][30];
// FOR DSU
int pset[MAX];
// FOR MAIN
int n, m, ans[MAX]; 
vector<ii> adjlist[MAX];
vector<node> edge;
vector<node> mst, anti_mst;

// DISJOINSET
void init(int k) {
    for (int i = 0; i <= MAX * 4 - 1; i++) {
        st[i] = INF;
        lazy[i] = INF;
    }
    for (int i = 1; i <= k; i++) {
        pset[i] = i;
    }
}

int findset(int i) {
    if (pset[i] == i) {
        return i;
    }
    return pset[i] = findset(pset[i]);
}

bool issameset(int i, int j) {
    if (findset(i) == findset(j)) {
        return true;
    }
    return false;
}

void unionset(int i, int j) {
    pset[findset(i)] = findset(j);
}

// SEGMENT TREE
void update(int v, int tl, int tr, int l, int r, int value) {
    if (lazy[v] != INF) {
        int nw = lazy[v];
        lazy[v] = INF;
        st[v] = min(nw, st[v]);
        if (tl != tr) {
            lazy[v * 2 + 1] = min(nw, lazy[v * 2 + 1]);
            lazy[v * 2 + 2] = min(nw, lazy[v * 2 + 2]);
        }
    }
    if (tl > r || tr < l) {
        return;
    }
    if (l <= tl && tr <= r) {
        st[v] = min(value, st[v]);
        if (tl != tr) {
            lazy[v * 2 + 1] = min(value, lazy[v * 2 + 1]);
            lazy[v * 2 + 2] = min(value, lazy[v * 2 + 2]);
        }
        return;
    }
    int mid = (tl + tr) >> 1;
    update(v * 2 + 1, tl, mid, l, r, value);
    update(v * 2 + 2, mid + 1, tr, l, r, value);
    st[v] = min(st[v * 2 + 1], st[v * 2 + 2]);
}

int getans(int v, int tl, int tr, int l, int r) {
    if (lazy[v] != INF) {
        int nw = lazy[v];
        lazy[v] = INF;
        st[v] = min(nw, st[v]);
        if (tl != tr) {
            lazy[v * 2 + 1] = min(nw, lazy[v * 2 + 1]);
            lazy[v * 2 + 2] = min(nw, lazy[v * 2 + 2]);
        }
    }
    if (tl > r || tr < l) {
        return INF;
    }
    if (l <= tl && tr <= r) {
        return st[v];
    }
    int mid = (tl + tr) >> 1;
    int left = getans(v * 2 + 1, tl, mid, l, r);
    int right = getans(v * 2 + 2, mid + 1, tr, l, r);
    return min(left, right);
}

// HEAVY LIGHT DECOMPOSITION
void dfs_hld(int pos, int parent) {
    setsize[pos] = 1;
    for (ii nw : adjlist[pos]) {
        int v = nw.second;
        if (v != parent) {
            depth[v] = depth[pos] + 1;
            par[v] = pos;
            dfs_hld(v, pos);
            setsize[pos] += setsize[v];
        }
    }
}

void decompose(int pos, int parent) {
    inchain[pos] = chain;
    pos_in_hld[pos] = ++cnt;
    if (head[chain] == 0) {
        head[chain] = pos;
    }
    int p = -1;
    for (ii nw : adjlist[pos]) {
        int v = nw.second;
        if (v != parent) {
            if (p == -1 || setsize[p] < setsize[v]) {
                p = v;
            }
        }
    }
    if (p == -1) {
        return;
    }
    decompose(p, pos);
    for (ii nw : adjlist[pos]) {
        int v = nw.second;
        if (v != p && v != parent) {
            chain++;
            decompose(v, pos);
        }
    }
}

// LCA
void dfs(int pos, int parent, int w) {
    in[pos] = ++timer;
    up[pos][0] = parent;
    for (int i = 1; i <= 20; i++) {
        up[pos][i] = up[up[pos][i - 1]][i - 1];
    }
    val[pos][0] = w;
    for (int i = 1; i <= 20; i++) {
        val[pos][i] = max(val[pos][i - 1], val[up[pos][i - 1]][i - 1]);
    }
    for (ii nw : adjlist[pos]) {
        int v = nw.second;
        int w = nw.first;
        if (parent != v) {
            dfs(v, pos, w);
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

int getval(int u, int v) {
    if (u == v) return 0;
    int res = 0;
    for (int j = 20 ; j >= 0 ; --j) {
        if (!ances(up[u][j] , v)) {
            res = max(res , val[u][j]);
            u = up[u][j];
        }
    }
    return max(res , val[u][0]);
}

int getnode(int u, int v) {
    for (int i = 20; i >= 0; i--) {
        if (!ances(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return u;
}

void update_path(int u, int v, int w) {
    while (head[inchain[u]] != head[inchain[v]]) {
        if (depth[head[inchain[u]]] > depth[head[inchain[v]]]) {
            swap(u, v);
        }
        update(1, 1, n, pos_in_hld[head[inchain[v]]], pos_in_hld[v], w);
        v = par[v];
    }
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    update(1, 1, n, pos_in_hld[u], pos_in_hld[v], w);
}

void input() {
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w, i});
    }
}

void solve() {
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if (issameset(u, v) == false) {
            unionset(u, v);
            adjlist[u].emplace_back(ii(w, v));
            adjlist[v].emplace_back(ii(w, u));
            mst.emplace_back(edge[i]);
        }
        else {
            anti_mst.emplace_back(edge[i]);
        }
    }
    dfs_hld(1, 0);
    decompose(1, 0);
    dfs(1, 1, 0);
    for (auto nw : anti_mst) {
        int u = nw.u;
        int v = nw.v;
        int w = nw.w;
        int root = lca(u, v);
        ans[nw.index] = max(getval(u, root), getval(v, root));
        int preu = getnode(u, root);
        int prev = getnode(v, root);
        if (preu != root) update_path(u , preu , w);
        if (prev != root) update_path(v , prev , w);
    }

    for (auto nw : mst) {
        int u = nw.u;
        int v = nw.v;
        if (u != par[v]) swap(u , v);
        ans[nw.index] = getans(1,1,n,pos_in_hld[v],pos_in_hld[v]);
        if (ans[nw.index] == INF) {
            ans[nw.index] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] - 1 << " ";
    }
}

signed main() {
    faster;
    input();
    solve();
}
