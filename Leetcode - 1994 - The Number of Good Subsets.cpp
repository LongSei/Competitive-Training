class Solution {
public:
    const static int mod = 1000000000 + 7;
    vector<int> prime = vector<int>({
        2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29
    }); // len = 11
    int get_bit(int number, int bit) {
        return (number >> bit) & 1;
    }
    
    vector<int> prime_squared = {4, 9, 25, 49, 81, 121, 169, 289, 361, 529, 841};

    int get_bit_state(int number) {
        int answer = 0;
        for (int bit = 0; bit < 11; bit++) {
            if (number % prime_squared[bit] == 0) {
                return 0;
            }
            if (number % prime[bit] == 0) {
                answer |= (1 << bit); 
            }
        }
        return answer;
    }

    int dp[2][2048]; 
    int numberOfGoodSubsets(vector<int>& nums) {
        int state = get_bit_state(nums[0]);
        dp[0][0] = 1;
        if (nums[0] == 1 && state == 0) {
            dp[0][state] += 1;
        } else if (state != 0) {
            dp[0][state] += 1;
        }

        int nums_size = nums.size(); 
        for (int index = 1; index < nums_size; index++) {
            for (int state = 0; state <= 2047; state++) {
                dp[index % 2][state] = 0;
            }
            
            int current_state = get_bit_state(nums[index]);
            for (int state = 0; state <= 2047; state++) {
                // Not take
                dp[index % 2][state] += dp[(index + 1) % 2][state];
                dp[index % 2][state] %= mod;

                // Check if could take or not
                bool can_take = true;
                if (state & current_state) {
                    can_take = false;
                } 
                if (current_state == 0 && nums[index] != 1) {
                    can_take = false;
                }

                // Take
                if (can_take == true) {
                    dp[index % 2][state | current_state] += dp[(index + 1) % 2][state];
                    dp[index % 2][state | current_state] %= mod;
                }
            }
        }
        int answer = 0;
        for (int state = 1; state <= 2047; state++) {
            answer += dp[(nums_size - 1) % 2][state];
            answer %= mod;
        }

        return answer;
    }
};
