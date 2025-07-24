class Solution {
    const static int MAX_BIT_INDEX = 30;
public:
    bool isBit(int number, int bit_index) {
        return number & (1 << bit_index);
    }

    int count_bit_for_array(vector<int>& arr, int bit_index) {
        int ans = 0;
        int array_size = arr.size(); 
        for (int index = 0; index < array_size; index++) {
            ans += isBit(arr[index], bit_index);
        }
        return ans;
    }
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for (int bit = 0; bit <= MAX_BIT_INDEX; bit++) {
            int cnt_1 = count_bit_for_array(arr1, bit);
            int cnt_2 = count_bit_for_array(arr2, bit);
            if (cnt_1 % 2 && cnt_2 % 2) {
                ans += (1 << bit);
            }
        }
        return ans;
    }
};