#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[MAX]; string s;
signed main() {
    faster;
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] * 10 + ((i % mod) * (s[i - 1] - '0'));
        dp[i] %= mod;
    }
    int ans = 0;
    for (int i = 1; i <= s.size(); i++) {
        ans += dp[i];
        ans %= mod;
    }
    cout << ans;
}
