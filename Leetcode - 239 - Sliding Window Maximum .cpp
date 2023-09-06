class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sparseTable[1000005][19];
        for (int i = 0; i < nums.size(); i++) {
            sparseTable[i][0] = nums[i];
        }

        for (int level = 1; level <= 17; level++) {
            for (int i = 0; i < nums.size(); i++) {
                sparseTable[i][level] = max(sparseTable[i][level - 1], sparseTable[i + (1 << (level - 1))][level - 1]);
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size() - (k - 1); i++) {
            int range = k;
            int level = 0;
            int ans = -10000005;
            int index = i;
            while (range) {
                if (range % 2 == 1) {
                    ans = max(ans, sparseTable[index][level]);
                    index = index + (1 << level);
                }
                level += 1;
                range >>= 1;
            }
            cout << endl;
            result.push_back(ans);
        }

        return result;
    }
};