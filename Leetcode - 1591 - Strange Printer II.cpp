class Solution {
public:
    bool check[65][65]; 
    int dp[65][65][2];
    int n;
    int m;
    void prepare(vector<vector<int>>& targetGrid, int value) {
        int checkNumber = (value == 0 ? 0 : 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j][checkNumber] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {dp[i][j][checkNumber] += dp[i - 1][j][checkNumber];}
                if (j > 0) {dp[i][j][checkNumber] += dp[i][j - 1][checkNumber];}
                if (i > 0 && j > 0) {dp[i][j][checkNumber] -= dp[i - 1][j - 1][checkNumber];}
                if (targetGrid[i][j] == value) {
                    dp[i][j][checkNumber] += 1;
                }
            }
        }
    }
    int calc(int left, int right, int up, int down, int checkNumber) {
        if (left == 0 && up == 0) {
            return dp[down][right][checkNumber];
        }
        if (left == 0) {
            return dp[down][right][checkNumber] - dp[up - 1][right][checkNumber];
        } 
        if (up == 0) {
            return dp[down][right][checkNumber] - dp[down][left - 1][checkNumber];
        }
        return dp[down][right][checkNumber] - dp[down][left - 1][checkNumber] - 
                dp[up - 1][right][checkNumber] + dp[up - 1][left - 1][checkNumber];
    }
    void assignZero(vector<vector<int>>& targetGrid, int left, int right, int up, int down) {
        for (int i = up; i <= down; i++) {
            for (int j = left; j <= right; j++) {
                targetGrid[i][j] = 0;
            }
        }
    }
    bool isPrintable(vector<vector<int>>& targetGrid) {
        n = targetGrid.size();
        m = targetGrid[0].size(); 
        while (true) {
            bool assign = false;
            bool remain = false;
            for (int number = 1; number <= 60; number++) {

                prepare(targetGrid, number);
                prepare(targetGrid, 0);

                int totalNumber = dp[n - 1][m - 1][1];
                if (totalNumber == 0) {continue;}
                remain = true;
                int left = 0, right = m - 1;
                int up = 0, down = n - 1; 
                while (dp[n - 1][left][1] == 0) {
                    left += 1;
                }
                while (right - 1 >= 0 && dp[n - 1][right - 1][1] == totalNumber) {
                    right -= 1;
                }
                while (dp[up][m - 1][1] == 0) {
                    up += 1;
                }
                while (down - 1 >= 0 && dp[down - 1][m - 1][1] == totalNumber) {
                    down -= 1;
                }
                int totalGrid = (right - left + 1) * (down - up + 1);
                int totalZero = calc(left, right, up, down, 0);
                if (totalGrid - totalNumber == totalZero) {
                    assignZero(targetGrid, left, right, up, down);  
                    assign = true;
                }
            }
            if (remain == true && assign == false) {
                return false;
            }
            if (remain == false) {
                return true;
            }
        }
    }
};