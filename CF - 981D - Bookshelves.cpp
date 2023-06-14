#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 55;
bool dp[MAX][MAX];
int prefix[MAX], n, k, arr[MAX];

signed main() {
    faster;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int ans = 0;
    for (int bit = 61; bit >= 0; bit--) {
        ans ^= (1ll << bit);
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int shelve = 1; shelve <= k; shelve++) {
            for (int i = shelve; i <= n; i++) {
                for (int j = shelve - 1; j <= i - 1; j++) {
                    if (dp[shelve - 1][j] == false) {
                        continue;
                    }
                    if ((ans & (prefix[i] - prefix[j])) != ans) {
                        continue;
                    }
                    dp[shelve][i] = true;
                }
            }
        }
        if (dp[k][n] == false) {
            ans ^= (1ll << bit);
        }
    }
    cout << ans;
}
