class Solution {
public:
    bool dp[2005][2005];
    bool check[2005][2005];
        bool jumpInto(int position, int preJump, vector<int>& stones) {
            if (position == stones.size() - 1) {
                check[position][preJump] = true;
                return dp[position][preJump] = true;
            }
            if (check[position][preJump] == false) {
                for (int i = position + 1; i < stones.size(); i++) {
                    int range = abs(stones[i] - stones[position]);
                    int check = abs(preJump - range);
                    if (check <= 1) {

                        dp[position][preJump] |= jumpInto(i, abs(stones[i] - stones[position]), stones);
                    }
                }
                check[position][preJump] = true;
                return dp[position][preJump];
            }
                return dp[position][preJump];
        }
    bool canCross(vector<int>& stones) {
        for (int i = 0; i <= stones.size(); i++) {
            for (int j = 0; j <= stones.size(); j++) {
                dp[i][j] = false;
                check[i][j] = false;
            }
        }
        
        if (stones[1] != 1) {
            return false;
        }
        bool isok = jumpInto(1, 1, stones);
        return isok;
    }
};