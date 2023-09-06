class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                bool check = false;
                int target = 0 - nums[i] - nums[j];
                int left = i + 1;
                int right = nums.size() - 1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (nums[mid] == target) {
                        check = true;
                        break;
                    }
                    else if (nums[mid] < target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                if (check == true) {
                    if (target >= nums[j] && target <= nums[i]) {
                        st.insert({nums[j], target, nums[i]});
                    }
                    else if (target >= nums[i]) {
                        st.insert({nums[j], nums[i], target});
                    }
                    else {
                        st.insert({target, nums[j], nums[i]});
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto v : st) {
            result.push_back(v);
        }
        return result;
    }
};