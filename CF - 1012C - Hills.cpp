#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 5e3 + 6;
const int INF = 1e9;
int n, arr[MAX];
int dp[MAX][MAX][2]; // DP[x][y][z] Biểu diễn trạng thái xét đến đồi thứ i, số cây đẹp là y và trạng thái của cây thứ i là z (1/0: Đẹp hay không đẹp)

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void reset() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
}

int cost(int i, int j) {
    // CUT I, KEEP J
    return max(0, arr[i] - arr[j] + 1);
}

void solve() {
    dp[0][0][0] = dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= (i + 1) >> 1; j++) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + cost(i, i - 1)); // Nếu không lấy cây thứ i là cây đẹp thì ta xét cây thứ i - 1. Nếu đẹp thì phải cộng chi phí cắt cây i để cây i - 1 đẹp
            if (j != 0) {
                dp[i][j][1] = min(dp[i - 2][j - 1][0] + cost(i - 1, i), dp[i - 2][j - 1][1] + max(cost(i - 1, i), cost(i - 1, i - 2)));
                // Nếu cây i lấy đẹp thì xét cây i - 2 -> Nếu i - 2 và i đều đẹp -> xét cây i - 1 với chi phí cho cả i - 2 và i
                                                    //    Nếu i - 2 không đẹp mà i đẹp -> chỉ xét cây i - 1 với chi phí cho i
            }
        }
    } 
    for (int i = 1; i <= (n + 1) >> 1; i++) {
        cout << min(dp[n][i][1], dp[n][i][0]) << " ";
    }
}

signed main() {
    faster;
    reset();
    input();
    solve();
}