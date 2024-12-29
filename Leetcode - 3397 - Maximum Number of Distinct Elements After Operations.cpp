class Solution {
public:
    map<int, bool> check; 
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int array_size = nums.size();
        int left_max = nums[0] - k;
        int right_max = nums[array_size - 1] + k;

        for (int index = 0; index < array_size; index++) {
            int current_number = nums[index];
            int left_interval = current_number - k;
            int right_interval = current_number + k;

            int fill = left_interval;

            int left = fill; 
            int right = right_interval;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (check[mid] == false) {
                    fill = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (check[fill] && fill > right_interval) {
                continue;
            } else {
                nums[index] = fill;
                check[fill] = true;
            }
        }

        set<int> new_nums;
        for (int index = 0; index < array_size; index++) {
            new_nums.insert(nums[index]);
        }

        return new_nums.size();
    }
};