#include<bits/stdc++.h>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAX = 5e4 + 1;
const int MAXLEN = 501;
int n, k, u, v, dp[MAX][MAXLEN], parent[MAX], ans = 0;
vector<int> adjlist[MAX];
// dp[x][y] (số nút con của nút x cách x một khoảng bằng y)

void dfs(int u, int p) {
    // Xây dựng dp
    // DFS tìm dp[a][b] (với mọi 1 <= a <= n && 0 <= b <= k) 
    int cnt = 0;
    parent[u] = p;
    for (int i = 0 ; i < adjlist[u].size(); i++) {
        if (adjlist[u][i] == p) {
            continue;
        }
        dfs(adjlist[u][i], u);
        cnt++;
    }
    dp[u][0] = 1;
    dp[u][1] = cnt;
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < adjlist[u].size(); j++) {
            if (adjlist[u][j] == p) {
                continue;
            }
            dp[u][i] += dp[adjlist[u][j]][i - 1];
        }
    }
}

signed main() {
    faster;
    cin >> n >> k;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    dfs(1,0); // khởi tạo các dp
    

    /* Ta thấy với mỗi đỉnh i của cây thì tổng số đường đi qua i có độ dài là k sẽ được chia thành 2 loại:

    * Loại 1: có 1 đầu mút là v: dễ thấy sẽ được tính bằng dp[i][k] (Tổng số nút con của i cách i một khoảng là k)

    * Loại 2: i nằm trên đoạn thẳng đó hay có thể nói là i nằm trên đoạn thẳng nhưng không phải là 1 trong 2 đầu mút
    sẽ có công thức tính như sau:
    -Định nghĩa:
    + Gọi 1 đỉnh con bất kì của i là u.
    + Cho một biến x chạy từ 1 đến k - 1 (vì khoảng cách từ i đến u là 1, nên tổng khoảng cách tối đa còn lại là k - 1. Xem các định nghĩa dưới để hiểu rõ hơn)
    + Tổng số đoạn thẳng bắt đầu từ i, không đi qua u và có độ dài là k - x, 
    được tính như sau: tổng số đoạn từ i có độ dài k - x, trừ đi tổng số đoạn từ u có độ dài k - x - 1 (dp[i][k - x] - dp[u][k - x - 1])
    + Tổng số đoạn thẳng từ u có độ dài là x - 1 (dp[u][x - 1])
    => Sau khi nối hai đoạn trên vào thì ta sẽ được 1 đoạn thẳng có độ dài là (k - x - 1) + (x - 1) + 1 (Số 1 ở cuối là đoạn i -> u)
    Chú ý: với công thức loại 2 thì khi tính các đoạn sẽ bị trùng nhau 2 lần nên tính xong cần chia đôi
    
    * Từ đó suy ra công thức tính ans = (Sum_Loại2_của_i / 2) + (Sum_Loại1_của_i) (với i chạy từ 1 đến n)*/

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= k - 1; x++) {
            for (int j = 0; j < adjlist[i].size(); j++) {
                if (adjlist[i][j] == parent[i]) {
                    continue;
                }
                ans += (dp[adjlist[i][j]][x - 1] * (dp[i][k - x] - dp[adjlist[i][j]][k - x - 1]));
            }
        }
    }
    ans >>= 1;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][k];
    }
    cout << ans;
}
