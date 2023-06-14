#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 200005;
int n; vector<int> adjlist[MAX];
int stat[MAX], timer = 0, in[MAX], out[MAX], st[MAX * 4], lazy[MAX * 4];

void dfs(int pos, int parent) {
    in[pos] = ++timer;
    for (int v : adjlist[pos]) {
        if (v != parent) {
            dfs(v, pos);
        }
    }
    out[pos] = timer;
}

void input() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adjlist[i].push_back(x);
        adjlist[x].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        stat[in[i]] = x;
    }
}

void build(int stat[], int v, int tl, int tr, int l, int r) {
    if (tl == tr) {
        st[v] = stat[tl];
        return;
    }
    int mid = (tl + tr) >> 1;
    build(stat, v * 2 + 1, tl, mid, l, r);
    build(stat, v * 2 + 2, mid + 1, tr, l, r);
    st[v] = st[v * 2 + 1] + st[v * 2 + 2];
}

void update(int v, int tl, int tr, int l, int r) {
    if (lazy[v] % 2 != 0) {
        st[v] = (tr - tl + 1) - st[v];
        if (tl != tr) {
            lazy[v * 2 + 1] += lazy[v];
            lazy[v * 2 + 2] += lazy[v];
            lazy[v * 2 + 1] %= 2;
            lazy[v * 2 + 2] %= 2;
        }
        lazy[v] = 0;
    }
    if (tl > r || tr < l) {
        return;
    }
    if (l <= tl && tr <= r) {
        st[v] = (tr - tl + 1) - st[v];
        if (tl != tr) {
            lazy[v * 2 + 1]++;
            lazy[v * 2 + 2]++;
        }
        return;
    }
    int mid = (tl + tr) >> 1;
    update(v * 2 + 1, tl, mid, l, r);
    update(v * 2 + 2, mid + 1, tr, l, r);
    st[v] = st[v * 2 + 1] + st[v * 2 + 2];
}

int query(int v, int tl, int tr, int l, int r) {
    if (lazy[v] % 2 != 0) {
        st[v] = (tr - tl + 1) - st[v];
        if (tl != tr) {
            lazy[v * 2 + 1] += lazy[v];
            lazy[v * 2 + 2] += lazy[v];
            lazy[v * 2 + 1] %= 2;
            lazy[v * 2 + 2] %= 2;
        }
        lazy[v] = 0;
    }    
    if (tl > r || tr < l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return st[v];
    }
    int mid = (tl + tr) >> 1;
    return query(v * 2 + 1, tl, mid, l, r) + query(v * 2 + 2, mid + 1, tr, l, r);
}

void solve() {
    build(stat, 1, 1,n, 1, n);
    int q; cin >> q;
    while (q--) {
        string s; int v;
        cin >> s >> v;
        if (s == "get") {
            cout << query(1,1,n,in[v],out[v]) << endl;
        }
        else {
            update(1,1,n,in[v],out[v]);
        }
    }
}

signed main() {
    faster;
    input();
    solve();
}