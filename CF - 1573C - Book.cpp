#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 2e5 + 5;
int n; vector<int> adjlist[MAX];
int par[MAX], dp[MAX], num[MAX], low[MAX], timer = 0;
bool check[MAX];
bool f = false;
stack<int> st;

void dfs(int pos) {
    check[pos] = true;
    if (adjlist[pos].size() == 0) {
        dp[pos] = 1;
        return;
    }
    for (int v : adjlist[pos]) {
        if (check[v] == false) {
            dfs(v);
        }
    }            
    for (int v : adjlist[pos]) {
        if (v > pos) {
            dp[pos] = max(dp[pos], dp[v] + 1);
        }
        else {
            dp[pos] = max(dp[pos], dp[v]);
        }
    }
}

void reset(int n) {
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = 0;
        check[i] = false;
        par[i] = 0;
        adjlist[i].clear();
        num[i] = 0;
        low[i] = 0;
    }
    timer = 0;
    f = false;
    st = stack<int>();
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
            low[pos] = min(low[pos], low[v]);
        }
    }
    if (low[pos] == num[pos] && f == false) {
        int indx;
        int tio = 0;
        do {
            tio++;
            indx = st.top();
            st.pop();
            num[indx] = low[indx] = INT_MAX;
        } while (indx != pos);
        if(tio >= 2) {
            f = true;
        }
    }
}

void solve() {
    cin >> n;
    reset(n);
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        for (int j = 1; j <= t; j++) {
            int x; cin >> x;
            par[x] = i;
            adjlist[i].emplace_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            tarjan(i);
        }
    }
    if (f == true) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) {
            adjlist[0].emplace_back(i);
        }
    }
    dfs(0);
    int ans = -1;
    for (int v : adjlist[0]) {
        if (dp[v] == 0) {cout << -1 << endl; return;}
        ans = max(ans, dp[v]);
    }
    cout << ans << endl;
}

signed main() {
    faster;
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}
