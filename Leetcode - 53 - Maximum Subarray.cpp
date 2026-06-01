class Solution {
public:
    const static int MAX_LENGTH = 100000; 
    int dp[MAX_LENGTH];
    int maxSubArray(vector<int>& nums) {
        dp[0] = max(0, nums[0]); 
        int answer = nums[0];
        for (int index = 1; index < nums.size(); index++) {
            dp[index] = max(dp[index - 1] + nums[index], nums[index]);
            answer = max(answer, dp[index]);
        }
        return answer;
    }
};
