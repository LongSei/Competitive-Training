class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005];
        int n = s.size(); 
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                dp[i][j] = 0;
            }
        }
        int ans = 1;
        int left = 1, right = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                if (s[i - 1] == s[j - 1] && (j + 2 >= i || dp[j + 1][i - 1] >= 1)) {
                    dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + 2);
                }
                if (ans < dp[j][i]) {
                    ans = dp[j][i];
                    left = j;
                    right = i;
                }
            }
        }
        string result = "";
        for (int i = left; i <= right; i++) {
            result = result + s[i - 1];
        }
        return result;
    }
};