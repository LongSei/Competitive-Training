#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 2e9 + 7;
const int MAX = 1e6 + 5;
int n, m;
int st[MAX * 4], lazy[MAX * 4];
struct DATA {
    int l, r, w;
    bool operator < (const DATA A) {
        return w < A.w;
    }
} segment[MAX];

void push(int id) {
    int t = lazy[id];
    st[id * 2] += t;
    st[id * 2 + 1] += t;
    lazy[id * 2] += t;
    lazy[id * 2 + 1] += t;
 
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int tl, int tr, int val) {
    if (l > tr || r < tl) return;
    if (l >= tl && r <= tr) {
        st[id] += val;
        lazy[id] += val;
        return;
    }
 
    push(id);
    int m = (l + r)/2;
    update(id * 2, l, m, tl, tr, val);
    update(id * 2 + 1, m + 1, r, tl, tr, val);
 
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        segment[i] = {u, v - 1, w};
    }
    sort(segment + 1, segment + 1 + n);
}

void solve() {
    int ans = INF;
    int last = 1;
    for (int i = 1; i <= n; i++) {
        while (last <= n && st[1] == 0) {
            update(1,1,m-1,segment[last].l,segment[last].r,1);
            last++;
        }
        if (st[1]) {
            ans = min(ans, segment[last - 1].w - segment[i].w);
        }
        update(1,1,m-1,segment[i].l, segment[i].r, -1);
    }
    cout << ans;
}

signed main() {
    faster;
    input();
    solve();
}
