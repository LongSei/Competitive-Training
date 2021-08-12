#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
const int INF = 1e9 + 7;

int calc(int a, int b) {
    int res = 0;
    while (1) {
        if (res >= INF) {
            return INF;
        }
        if (a == 0 || b == 0) {
            return INF;
        }
        if (a == 1 && b == 1) {
            return res;
        }
        res++;
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
}

void solve() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, calc(n, i));
        }
        cout << ans << endl;
    }
}

signed main() {
    faster;
    solve();
}
