class Solution {
public:
    const static int MAX_LENGTH = 1e5 + 5;
    const static int mod = 1e9 + 7;
    int dp[MAX_LENGTH][3];
    int numberOfWays(string corridor) {
        // pos, acc_seat
        int corridor_size = corridor.size(); 
        corridor = '$' + corridor;

        dp[0][0] = 1;
        for (int index = 1; index <= corridor_size; index++) {
            if (corridor[index] == 'S') {
                // Not close 
                if (index < corridor_size) {
                    dp[index][1] += dp[index - 1][0] % mod;
                    dp[index][2] += dp[index - 1][1] % mod;
                }

                // Close
                dp[index][0] += dp[index - 1][1] % mod;
            } else {
                // Not close 
                if (index < corridor_size) {
                    dp[index][0] += dp[index - 1][0] % mod;
                    dp[index][1] += dp[index - 1][1] % mod;
                    dp[index][2] += dp[index - 1][2] % mod;
                }

                // Close
                dp[index][0] += dp[index - 1][2] % mod;
            }
        }
        return dp[corridor_size][0] % mod;
    }
};
