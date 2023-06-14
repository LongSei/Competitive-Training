#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int n, total_dist[MAX], one_go_and_not_go_back[MAX];
vector<ii> adjlist[MAX];

void dfs(int pos, int parent) {
    total_dist[pos] = 0;
    for (auto v : adjlist[pos]) {
        if (v.first != parent) {
            dfs(v.first, pos);
            total_dist[pos] += total_dist[v.first] + v.second;
        }
    }
    for (auto v : adjlist[pos]) {
        if (v.first != parent) {
            one_go_and_not_go_back[pos] = min(one_go_and_not_go_back[pos], 2 * (total_dist[pos] - total_dist[v.first] - v.second) + one_go_and_not_go_back[v.first] + v.second);
        }
    }
    if (one_go_and_not_go_back[pos] == 1e15 + 7) {
        one_go_and_not_go_back[pos] = 0;
    }
}

signed main() {
    faster;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adjlist[u].emplace_back(v, w);
        adjlist[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        one_go_and_not_go_back[i] = 1e15 + 7;
    }
    dfs(1, 1);
    cout << one_go_and_not_go_back[1];
}
