#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n, st[MAX * 4], lazy[MAX * 4];
#define ii pair<int, int> 
vector<pair<int, ii> > q;

bool cmp(pair<int, ii> a, pair<int, ii> b) {
    if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
    }
    return a.second.second > b.second.second;
}

signed main() {
    faster;
    cin >> n;
    for (int i= 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        q.push_back(make_pair(i, ii(u, v)));
    }
    sort(q.begin(), q.end(), cmp);
    for (int i = 0; i < q.size() - 1; i++) {
        if (q[i].second.first <= q[i + 1].second.first) {
            cout << q[i + 1].first;
            return 0;
        }
    }
    for (int i = 0; i < q.size() - 1; i++) {
        if (i + 2 < q.size()) {
            if (q[i].second.first - 1 <= q[i + 2].second.second) {
                cout << q[i + 1].first;
                return 0;
            }
        }
    }
    cout << -1;
}
