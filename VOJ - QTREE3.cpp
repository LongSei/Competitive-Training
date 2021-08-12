#include <bits/stdc++.h>
using namespace std;

#define nmax 100010

int n, q, t, v, ans, parent[nmax], heavy[nmax], depth[nmax], pos[nmax], head[nmax], order[nmax];
int col[nmax], fen[nmax];
vector <int> adj[nmax];

int dfs(int u)
{
    int Tsize = 1, max_Tsize = 0, c;
    heavy[u] = -1;
    for(int v: adj[u]) {
        if(v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            c = dfs(v);
            Tsize += c;
            if(max_Tsize < c)
                max_Tsize = c, heavy[u] = v;
        }
    }
    return Tsize;
}

void decompose(int u, int h)
{
    static int cnt = 0;
    head[u] = h;
    pos[u] = ++cnt;
    order[cnt] = u;
    if(heavy[u] != -1)
        decompose(heavy[u], h);
    for(int v: adj[u]) {
        if(v != heavy[u] && v != parent[u])
            decompose(v, v);
    }
}

void update(int x, int val)
{
    for(; x <= n; x += x&-x)
        fen[x] += val;
}

int get(int x)
{
    int res = 0;
    for(; x > 0; x &= x - 1) {
        res += fen[x];
    }
    return res;
}

int get(int l, int r)
{
    return get(r) - get(l - 1);
}

void findBlack(int l, int r, int& res)
{
    int mi;
    while(l <= r) {
        mi = (l + r) / 2;
        if(get(l, mi) > 0) {
            res = order[mi];
            r = mi - 1;
        }
        else {
            l = mi + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    memset(col, 0, sizeof(col));
    memset(fen, 0, sizeof(fen));

    cin >> n >> q;
    for(int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = parent[1] = 0;
    dfs(1);
    decompose(1, 1);

    while(q--) {
        cin >> t >> v;
        if(t) {
            ans = -1;
            for(; head[v] != 1; v = parent[head[v]]) {
                findBlack(pos[head[v]], pos[v], ans);
            }
            findBlack(pos[1], pos[v], ans);
            cout << ans << '\n';
        }
        else {
            update(pos[v], col[v] ? -1 : 1);
            col[v] = !col[v];
        }
    }

    return 0;
}
