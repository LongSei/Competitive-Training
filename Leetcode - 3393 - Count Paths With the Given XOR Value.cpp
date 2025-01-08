class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        long long dp[305][305][16];
        int n = grid.size();
        int m = grid[0].size();

        for (int xCoor = 0; xCoor < n; xCoor++) {
            for (int yCoor = 0; yCoor < m; yCoor++) {
                for (int value = 0; value < 16; value++) {
                    dp[xCoor][yCoor][value] = 0;
                }
            }
        }
        dp[0][0][grid[0][0]] = 1;

        int mod = 1000000007;

        for (int xCoor = 0; xCoor < n; xCoor++) {
            for (int yCoor = 0; yCoor < m; yCoor++) {
                for (int value = 0; value < 16; value++) {
                    dp[xCoor][yCoor][value] %= mod;
                    if (yCoor + 1 < m) {dp[xCoor][yCoor + 1][value ^ grid[xCoor][yCoor + 1]] += dp[xCoor][yCoor][value];}
                    if (xCoor + 1 < n) {dp[xCoor + 1][yCoor][value ^ grid[xCoor + 1][yCoor]] += dp[xCoor][yCoor][value];}
                }
            }
        }
        return dp[n - 1][m - 1][k];
    }
};