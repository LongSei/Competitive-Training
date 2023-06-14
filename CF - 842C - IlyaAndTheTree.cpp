#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n, dp[MAX][2], value[MAX], ans[MAX];
vector<int> adjlist[MAX];
set<int> least[MAX];

int GCD(int a, int b) {
    if (a % b == 0) {return b;}
    return GCD(b, a % b);
}

void dfs(int pos, int parent, int total) {
    for (auto v : least[parent]) {
        least[pos].insert(GCD(v, value[pos]));
    }
    least[pos].insert(total);
    least[pos].insert(GCD(total, value[pos]));
    total = GCD(total, value[pos]);
    for (int v : adjlist[pos]) {
        if (v != parent) {
            dfs(v, pos, total);
        }
    }
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adjlist[u].emplace_back(v);
        adjlist[v].emplace_back(u);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = *least[i].rbegin();
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
