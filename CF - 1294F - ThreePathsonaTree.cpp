#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n, parent[MAX], height[MAX], chain[MAX], timer = 0, depth[MAX], pos_in_hld[MAX], nchild[MAX];
vector<int> adjlist[MAX];
int res = 0, maxi = 0;

void dfs_for_hld(int pos) {
    int p = -1;
    nchild[pos] = 1;
    for (int i = 0; i < adjlist[pos].size(); i++) {
        int next = adjlist[pos][i];
        if (next == parent[pos]) {
            continue;
        }
        parent[next] = pos;
        depth[next] = depth[pos] + 1;
        dfs_for_hld(next);
        nchild[pos] += nchild[next];
        if (p == -1 || nchild[next] > nchild[adjlist[pos][p]]) {
            p = i;
        }
    }
    if (p != -1) {
        swap(adjlist[pos][0], adjlist[pos][p]);
    }
}

void hld(int pos, int chain_nw) {
    chain[pos] = chain_nw;
    pos_in_hld[pos] = ++timer;
    if (adjlist[pos].empty()) {
        return;
    }
    if (parent[pos] != adjlist[pos][0]) {
        hld(adjlist[pos][0], chain_nw);
    }
    for (int i = 1; i < adjlist[pos].size(); i++) {
        if (parent[pos] == adjlist[pos][i]) {
            continue;
        }
        hld(adjlist[pos][i], adjlist[pos][i]);
    }
}

int lca(int u, int v) {
    while (chain[u] != chain[v]) {
        if (depth[chain[u]] > depth[chain[v]]) {
            swap(u, v);
        }
        v = parent[chain[v]];
    }
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    return u;
}

void dfs(int pos, int parent, int nw) {
    height[pos] = nw;
    if (height[pos] > maxi) {
        res = pos;
        maxi = height[pos];
    }
    for (int i = 0; i < adjlist[pos].size(); i++) {
        if (adjlist[pos][i] == parent) {
            continue;
        }
        dfs(adjlist[pos][i], pos, nw + 1);
    }
}

int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - (2 * depth[l]);
}

int range(int u, int v, int z) {
    return (dist(u, v) + dist(v, z) + dist(z, u)) / 2;
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].emplace_back(v);
        adjlist[v].emplace_back(u);
    }
    dfs_for_hld(1);
    hld(1, 1);
    dfs(1, -1, 0);
    int first = res;
    res = 0, maxi = 0;
    dfs(first, -1, 0);
    int second = res;
    res = 0, maxi = 0;
    int third;
    for (int i = 1; i <= n; i++) {
        if (i == first || i == second) {
            continue;
        }
        int val = range(first, second, i);
        if (val > maxi) {
            maxi = val;
            third = i;
        }
    }
    cout << maxi << endl;
    cout << first << " " << second << " " << third;
}