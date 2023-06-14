#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 505;
int n, dp[MAX][MAX]; string s;

int solve(int l, int r) {
    int &res = dp[l][r];
    if (res != -1) {
        return res;
    }
    if (l > r) {
        return res = 0;
    }
    if (l == r) {
        return res = 1;
    }
    res = 1 + solve(l + 1, r);
    for (int i = l + 1; i <= r; i++) {
        if (s[l] == s[i])
            res = min(res, solve(l + 1, i - 1) + solve(i, r));
    }
    return res;
}

signed main() {
    faster;
    memset(dp, -1, sizeof(dp));
    cin >> n >> s;
    cout << solve(0, n - 1);
}