class Solution {
public:
    const static int MAX_LENGTH = 100005;
    const static int MAX_INTEGER = 100000;
    const static int MAX_PRIME_SCORE = 7 + 1;
    const static int MOD = 1000000000 + 7;

    int prime_score[MAX_LENGTH];
    int next_position_with_prime_score[2][MAX_PRIME_SCORE][MAX_LENGTH]; 
    
    vector<int> prime_number;
    int amount_root[MAX_INTEGER + 1];
    // 0: Left -> Right; 
    // 1: Right -> Left;

    int fast_pow(int base, int level) {
        long long result = 1; 
        long long b = base % MOD; 

        while (level > 0) {
            if (level & 1) {  
                result = (result * b) % MOD;  
            }
            b = (b * b) % MOD; 
            level >>= 1;  
        }
        return (int)result;
    }

    void prepare_prime_number() {
        for (int root = 2; root <= MAX_INTEGER; root++) {
            if (amount_root[root] == 0) {
                amount_root[root] += 1;
                prime_number.push_back(root);
                int root_multi = root * 2; 
                while (root_multi <= MAX_INTEGER) {
                    amount_root[root_multi] += 1;
                    root_multi += root;
                }
            }
        }
    }

    void prepare_prime_score(vector<int>& nums) {
        int nums_size = nums.size(); 
        prepare_prime_number();
        for (int index = 0; index < nums_size; index++) {
            prime_score[index] = amount_root[nums[index]];
        }
    }  

    void prepare_next_position_with_prime_score(int& nums_size) {
        // 1: Right -> Left Case
        for (int score = 0; score < MAX_PRIME_SCORE; score++) {
            if (prime_score[0] == score) {
                next_position_with_prime_score[1][score][0] = 0;
            } else {
                next_position_with_prime_score[1][score][0] = -1;
            }
        } 
        for (int index = 1; index < nums_size; index++) {
            for (int score = 0; score < MAX_PRIME_SCORE; score++) {
                if (prime_score[index] == score) {
                    next_position_with_prime_score[1][score][index] = index;
                } else {
                    next_position_with_prime_score[1][score][index] = next_position_with_prime_score[1][score][index - 1];
                }
            }
        }

        // 0: Left -> Right Case
        for (int score = 0; score < MAX_PRIME_SCORE; score++) {
            if (prime_score[nums_size - 1] == score) {
                next_position_with_prime_score[0][score][nums_size - 1] = nums_size - 1;
            } else {
                next_position_with_prime_score[0][score][nums_size - 1] = -1;
            }
        } 
        for (int index = nums_size - 2; index >= 0; index--) {
            for (int score = 0; score < MAX_PRIME_SCORE; score++) {
                if (prime_score[index] == score) {
                    next_position_with_prime_score[0][score][index] = index;
                } else {
                    next_position_with_prime_score[0][score][index] = next_position_with_prime_score[0][score][index + 1];
                }
            }
        }
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int nums_size = nums.size();

        prepare_prime_score(nums);
        prepare_next_position_with_prime_score(nums_size);

        priority_queue<pair<int, int>> pq; 
        for (int index = 0; index < nums_size; index++) {
            pq.push(pair<int, int>(nums[index], index));
        }

        long long answer = 1;
        while (pq.empty() == false && k > 0) {
            pair<int, int> front = pq.top(); pq.pop(); 
            int current_value = front.first;
            int current_index = front.second;
            int current_prime_score = prime_score[current_index];

            int left_take_position = 0;
            int right_take_position = nums_size - 1;
            for (int score = current_prime_score; score <= 7; score++) {
                int left_position = next_position_with_prime_score[1][score][max(0, current_index - 1)];
                int right_position = next_position_with_prime_score[0][score][min(nums_size - 1, current_index + 1)];

                if (left_position != -1) {
                    left_take_position = min(current_index, max(left_take_position, left_position + 1));
                } 
                if (right_position != -1 && score > current_prime_score) {
                    right_take_position = max(current_index, min(right_take_position, right_position - 1));
                }
            }

            if (left_take_position > nums_size - 1 || left_take_position < 0) {
                left_take_position = -1;
            } 
            if (right_take_position > nums_size - 1 || right_take_position < 0) {
                right_take_position = -1;
            } 

            long long left_amount = (left_take_position == -1 ? 0 : current_index - left_take_position) + 1;
            long long right_amount = (right_take_position == -1 ? 0 : right_take_position - current_index) + 1;
            long long amount_sub = left_amount * right_amount; 
            long long amount_take = k < amount_sub ? k : amount_sub;
            
            answer *= fast_pow(current_value, amount_take);
            answer %= MOD;
            k -= amount_take;
        }
        return answer;
    }
};
