class Solution {
public:
    int amount_number[1005][1005];

    long long numberOfSubsequences(vector<int>& nums) {
        int array_size = nums.size();
        amount_number[0][nums[0]] = 1;
        for (int index = 1; index < array_size; index++) {
            for (int value = 1; value <= 1000; value++) {
                amount_number[index][value] = amount_number[index - 1][value];
            }

            int current_value = nums[index];
            amount_number[index][current_value] += 1;
        }

        long long ans = 0;
        for (int p = 0; p < array_size; p++) {
            for (int r = p + 4; r < array_size; r++) {
                int product = nums[p] * nums[r];

                for (int q_value = 1; q_value * q_value <= product; q_value++) {
                    if (product % q_value == 0 && q_value <= 1000 && product <= 1000 * q_value && 
                        r + 2 < array_size) {
                        int elem_one = product / q_value;
                        int elem_two = q_value;

                        if (elem_one != elem_two) {
                            // Case q = elem_one
                            ans += (amount_number[r - 2][elem_one] - amount_number[(p + 2) - 1][elem_one]) * (amount_number[array_size - 1][elem_two] - amount_number[(r + 2) - 1][elem_two]);
                            // Case q = elem_two
                            ans += (amount_number[r - 2][elem_two] - amount_number[(p + 2) - 1][elem_two]) * (amount_number[array_size - 1][elem_one] - amount_number[(r + 2) - 1][elem_one]);
                        } else {
                            ans += (amount_number[r - 2][elem_one] - amount_number[(p + 2) - 1][elem_one]) * (amount_number[array_size - 1][elem_two] - amount_number[(r + 2) - 1][elem_two]);
                        }
                    }
                }
            }
        }

        return ans;
    }
};