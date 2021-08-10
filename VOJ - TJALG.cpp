#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e5 + 5;
int num[MAX], low[MAX], n, m, timer = 0, ans = 0;
stack<int> st;
vector<int> adjlist[MAX];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].emplace_back(v);
    }
}

void tarjan(int pos) {
    num[pos] = low[pos] = ++timer;
    st.push(pos);
    for (int v : adjlist[pos]) {
        if (num[v]) {
            low[pos] = min(low[pos], num[v]);
        }
        else {
            tarjan(v);
            low[pos] = min(low[v], low[pos]);
        }
    }
    if (low[pos] == num[pos]) {
        int indx;
        ans++;
        do {
            indx = st.top();
            st.pop();
            num[indx] = low[indx] = INT_MAX;
        } while (indx != pos);
    }
}

signed main() {
    faster;
    input();
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            tarjan(i);
        }
    }
    cout << ans;
}
