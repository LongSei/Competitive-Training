#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 5005;
int n, arr[MAX], dp[MAX][MAX];
vector<int> a = {0}, b = {0};
const int INF = 1e9;

// Để ý giả sử ta gọi các vị trí ban đầu là x1, x2,... và các vị trí kết thúc là y1, y2,...
// Ta sẽ chứng minh để thời gian đổi chỗ là ít nhất thì x[k] phải được nối với y[k] tương ứng (Xét hai cặp (x, y) liền kề để chứng minh)
// Từ đó suy ra ta sẽ sử dụng được quy hoạch động với dp[i][j]: i là số lượng điểm xuất phát được dùng và j là số lượng diểm có KHẢ NĂNG làm điểm kết thúc
// -> dp[i][j] = dp[i - 1][j - 1] + abs(x[i] - y[j]) - Nếu chọn i và j là 1 cặp (bắt đầu và kết thúc tương ứng)
// -> dp[i][j] = dp[i][j - 1] - Nếu không chọn điểm j là điểm kết thúc tương ứng với i
// -> Ta có công thức quy hoạch động là dp[i][j] = min(dp[i - 1][j - 1] + abs(x[i] - y[j]), dp[i][j - 1])

signed main() {
	faster;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}
	n = a.size() - 1;
	int m = b.size() - 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = INF;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i] - b[j]), dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
}