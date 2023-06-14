#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define pii pair<int, ii> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;

pii node[MAX]; int n, k;
int prefix[MAX][3];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        node[i] = make_pair(w, ii(u, v));
    }
    vector<int> only_a;
    vector<int> only_b;
    vector<int> both;
    for (int i = 1; i <= n; i++) {
        if (node[i].second.second == 0 && node[i].second.first == 0) {
            continue;
        }
        if (node[i].second.second == node[i].second.first) {
            both.emplace_back(node[i].first);
        }
        else if (node[i].second.first == 1) {
            only_a.emplace_back(node[i].first);
        }
        else if (node[i].second.second == 1) {
            only_b.emplace_back(node[i].first);
        } 
    }
    sort(only_a.begin(), only_a.end());
    sort(only_b.begin(), only_b.end());
    int nw_siz = min(only_a.size(), only_b.size());
    for (int i = 0; i < nw_siz; i++) {
        both.emplace_back(only_a[i] + only_b[i]);
    }
    sort(both.begin(), both.end());
    if (both.size() < k) {
        cout << -1;
        return;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += both[i];
    }
    cout << ans;
}

signed main() {
    faster;
    solve();
}
