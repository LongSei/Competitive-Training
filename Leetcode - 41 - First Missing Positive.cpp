class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini = 1000000;
        int maxi = 0;
        int n = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i-1] > 0) {
                n += 1;
                maxi = max(maxi, nums[i-1]);
                mini = min(mini, nums[i-1]);
            }
            if (nums[i-1] == 0) {
                nums[i-1] = 1000000;
            }
        }
        if (mini > 1) {
            return 1;
        }
        maxi = n;

        for (int i = 0; i <= nums.size() - 1; i++) {
            if (nums[i] >= mini && nums[i] <= maxi) {
                int index = i;
                bool check = false;
                while (nums[index] >= mini && nums[index] <= maxi) {
                    int nextIndex = nums[index] - 1;
                    if (check == true) nums[index] = 0;
                    index = nextIndex;
                    check = true;
                }
                if (nums[index] < 0) {
                    nums[index] = 1000000;
                }
                if (nums[index] > 0) {
                    nums[index] = 0;
                }
            }
            if (nums[i] < 0) {
                nums[i] = 1000000;
            }
        }
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (nums[i] != 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};