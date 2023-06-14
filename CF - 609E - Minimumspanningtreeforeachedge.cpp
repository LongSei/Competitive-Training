#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<int, int> ii;
typedef pair<ii, ii> pii;
const int MAX = 2e5 + 5;
const int INF = 1e9 + 7;
vector<pii> edge;
vector<int> adjlist[MAX];
int pset[MAX];
int cnt, cnt_chain, timer = 0;
int in[MAX], out[MAX], up[MAX][20];
int inchain[MAX], head[MAX], pos_in_hld[MAX], parent[MAX], depth[MAX], setsize[MAX];
int st[MAX * 4], lazy[MAX * 4], value[MAX];
int res[MAX];
int n, m;
// Some spanning tree is minimal if and only if the weight of any other edge (x, y) (not from spanning tree) is not less than the weight of the heaviest edge on the path from x to y in spanning tree.

void init(int k) {
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
    i = findset(i);
    j = findset(j);
    if (pset[i] == pset[j]) {
        return true;
    }
    return false;
}
void unionset(int i, int j) {
    pset[findset(i)] = findset(j);
}

void dfs(int pos, int par) {
    setsize[pos] = 1;
    in[pos] = ++timer;
    up[pos][0] = par;
    for (int i = 1; i <= 18; i++) {
        up[pos][i] = up[up[pos][i - 1]][i - 1];
    }
    for (int v : adjlist[pos]) {
        if (v != par) {
            depth[v] = depth[pos] + 1;
            parent[v] = pos;
            dfs(v, pos);
            setsize[pos] += setsize[v];
        }
    }
    out[pos] = ++timer;
}

bool ances(int u, int v) {
    if (in[u] <= in[v] && out[u] >= out[v]) {
        return true;
    }
    return false;
}

int lca(int u, int v) {
    if (ances(u, v)) {
        return u;
    }
    if (ances(v, u)) {
        return v;
    }
    for (int i = 18; i >= 0; i--) {
        if (!ances(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void decompose(int pos, int par) {
    inchain[pos] = cnt_chain;
    pos_in_hld[pos] = ++cnt;
    if (head[cnt_chain] == 0) {
        head[cnt_chain] = pos;
    }
    int p = -1;
    for (int v : adjlist[pos]) {
        if (v != par) {
            if (p == -1 || setsize[p] < setsize[v]) {
                p = v;
            }
        }
    }
    if (p == -1) {
        return;
    }
    decompose(p, pos);
    for (int v : adjlist[pos]) {
        if (v != par && v != p) {
            cnt_chain++;
            decompose(v, pos);
        }
    }
}

void build(int arr[], int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = arr[tl];
        return;
    }
    int mid = (tl + tr) >> 1;
    build(arr, v * 2 + 1, tl, mid);
    build(arr, v * 2 + 2, mid + 1, tr);
    st[v] = max(st[v * 2 + 1], st[v * 2 + 2]);
} 

int query(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) {
        return -1;
    }
    if (l <= tl && tr <= r) {
        return st[v];
    }
    int mid = (tl + tr) >> 1;
    return max(query(v * 2 + 1, tl, mid, l, r), query(v * 2 + 2, mid + 1, tr, l, r));
}

int getans(int u, int v) {
    int res = -1;
    while (head[inchain[u]] != head[inchain[v]]) {
        if (depth[head[inchain[u]]] < depth[head[inchain[v]]]) {
            swap(u, v);
        }
        int add = query(1,1,n,pos_in_hld[head[inchain[u]]], pos_in_hld[u]);
        res = max(res, add);
        u = parent[head[inchain[u]]];
    }
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    int add = query(1,1,n,pos_in_hld[u] + 1, pos_in_hld[v]);
    res = max(res,add);
    return res;
}

void input() {
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.emplace_back(ii(w, i), ii(u, v));
    }
    int mst = 0;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        if (issameset(edge[i].second.first, edge[i].second.second) == false) {
            adjlist[edge[i].second.first].emplace_back(edge[i].second.second);
            adjlist[edge[i].second.second].emplace_back(edge[i].second.first);
            unionset(edge[i].second.first, edge[i].second.second);
            res[edge[i].first.second] = -1;
            mst += edge[i].first.first;
        }
    }
    parent[1] = 1;
    dfs(1,1);
    decompose(1,1);    
    for (int i = 0; i < edge.size(); i++) {
        if (res[edge[i].first.second] == -1) {
            res[edge[i].first.second] = mst;
            int u = edge[i].second.first;
            int v = edge[i].second.second;
            if (depth[u] > depth[v]) {
                swap(u, v);
            }
            value[pos_in_hld[v]] = edge[i].first.first;
        }
    }
    build(value,1,1,n);
    for (int i = 0; i < edge.size(); i++) {
        pii nw = edge[i];
        if (res[edge[i].first.second] == 0) {
            int par = lca(nw.second.second, nw.second.first);
            res[edge[i].first.second] = mst - getans(nw.second.second, nw.second.first) + nw.first.first;
        }
    }
    for (int i = 0; i < edge.size(); i++) {
        cout << res[i + 1] << endl;
    }
}

signed main() {
    faster;
    input();
}
