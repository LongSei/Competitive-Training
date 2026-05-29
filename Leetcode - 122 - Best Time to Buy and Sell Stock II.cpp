class Solution {
public:
    const static int MAX_DAYS = 3*10000; 
    const static int HAVE_OR_NOT_STATE = 2; 
    const static int HAVE_STOCK = 1;
    const static int NO_STOCK = 0;

    int dp[MAX_DAYS][HAVE_OR_NOT_STATE]; 
    int maxProfit(vector<int>& prices) {
        int amount_day = prices.size(); 
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for (int index = 1; index < amount_day; index++) {
            dp[index][1] = max(dp[index - 1][1], dp[index - 1][0] - prices[index]);
            dp[index][0] = max(dp[index - 1][1] + prices[index], dp[index - 1][0]);
        }
        return dp[amount_day - 1][0];
    }
};
