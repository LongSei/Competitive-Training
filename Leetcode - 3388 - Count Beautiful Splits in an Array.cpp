class Solution {
public:
    vector<vector<int>> maximum_match;
    void prepare_maximum_match(vector<int>& nums) {
        int nums_size = nums.size(); 
        maximum_match = vector<vector<int>>(nums_size, vector<int>(nums_size, 0));
        for (int index_one = nums_size - 1; index_one >= 0; index_one--) {
            for (int index_two = nums_size - 1; index_two >= index_one + 1; index_two--) {
                if (index_one + 1 < nums_size && index_two + 1 < nums_size) maximum_match[index_one][index_two] = maximum_match[index_one + 1][index_two + 1];
                if (nums[index_one] == nums[index_two])  maximum_match[index_one][index_two] += 1;
                else  maximum_match[index_one][index_two] = 0;
            }
        }
    }

    bool check_prefix(int start_index_one, int end_index_one, int start_index_two, int end_index_two) {
        int one_size = end_index_one - start_index_one + 1;
        int two_size = end_index_two - start_index_two + 1;
        if (two_size >= one_size && maximum_match[start_index_one][start_index_two] >= one_size) {
            return true;
        }
        return false;
    }

    int beautifulSplits(vector<int>& nums) {
        // 2 index splitter 
        // Loop to get num1 and num2 + num3 O(N)
        // -> check prefix O(N)
        // Loop to get num2 and num3 O(N)
        // -> O(N^2)
        
        int ans = 0;
        prepare_maximum_match(nums);
        int nums_size = nums.size();
        for (int splitter_one = 0; splitter_one <= (nums_size - 1); splitter_one++) {
            for (int splitter_two = splitter_one + 1; splitter_two <= (nums_size - 1) - 1; splitter_two++) {
                if ((check_prefix(0, splitter_one, splitter_one + 1, splitter_two)) ||
                    (check_prefix(splitter_one + 1, splitter_two, splitter_two + 1, nums_size - 1))) {
                    ans += 1;   
                } 
            }
        }
        return ans;
    }
};