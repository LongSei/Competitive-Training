#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int n; vector<int> adjlist[MAX];
bool check[MAX]; int ans[MAX];
int res = 0; bool d[MAX];
void dfs(int pos, int parent = 0) {
    d[pos] = true;
    for (int v : adjlist[pos]) {
        if (d[v] == false) {
            dfs(v, pos);
        }
    }
    if (parent == 0) {
        return;
    }
    if (check[pos] == false && check[parent] == false) {
        check[pos] = true;
        check[parent] = true;
        swap(ans[pos], ans[parent]);
        res += 2;
    }
}

signed main() {
    faster;
    cin >> n;
    for (int i= 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adjlist[u].emplace_back(v);
        adjlist[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (check[i] == true) {
            continue;
        }
        for (auto v : adjlist[i]) {
            if (check[i] == true) {
                continue;
            }
            check[i] = true;
            swap(ans[i], ans[v]);
            res += 2;
        }
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
