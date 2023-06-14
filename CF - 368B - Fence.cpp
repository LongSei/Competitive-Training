#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 2e5 + 1;
const int INF = 1e9;
int n, k, arr[MAX], dp[MAX], sum[MAX], ans;

signed main() {
    faster;
    cin >> n >> k;
    sum[0] = 0;
    int s = 0;
    ans = INF;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = k; i <= n; i++) {
        if (ans > (sum[i] - sum[i - k])) {
            ans = sum[i] - sum[i - k];
            s = i - k + 1;
            // cout << i << endl;
        }
    }
    cout << s;
}
