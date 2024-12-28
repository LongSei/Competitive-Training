class Solution {
public:
    vector<pair<char, int>> prepare_character_and_amount(string& s) {
        char current_character = '!';
        int amount_character = 0;
        int string_size = s.size();

        vector<pair<char, int>> character_and_amount; 

        for (int index = 0; index < string_size; index++) {
            char character = s[index];
            if (character != current_character && current_character != '!') {
                character_and_amount.push_back(pair<char, int>(current_character, amount_character));
                amount_character = 0;
                current_character = character;
            } else if (character != current_character) {
                current_character = character;
            }
            amount_character += 1;
        }

        if (amount_character > 0) {
            character_and_amount.push_back(pair<char, int>(current_character, amount_character));
        }

        return character_and_amount;
    }
    int solve_length_one(string& s) {
        int one_even = 0;
        int one_odd = 0;
        int zero_even = 0;
        int zero_odd = 0;

        int string_size = s.size();
        for (int index = 0; index < string_size; index++) {
            char character = s[index];
            if (index % 2 == 0) {
                if (character == '0') {
                    zero_even += 1;
                } else {
                    one_even += 1;
                }
            } else {
                if (character == '0') {
                    zero_odd += 1;
                } else {
                    one_odd += 1;
                }
            }
        }

        int min_ops = INT_MAX;
        // Case zero first
        int ops = one_even + zero_odd;
        min_ops = min(ops, min_ops);

        // Case zero second
        ops = one_odd + zero_even;
        min_ops = min(ops, min_ops);
        return min_ops;
    }
    
    map<pair< pair<int, int>, vector<pair<char, int>> > , bool> check;
    bool is_ok(int min_length, vector<pair<char, int>>& character_and_amount, int numOps) {
        int tuple_size = character_and_amount.size(); 
        int remainOps = numOps; 

        // Construct the key properly with parentheses
        auto key = make_pair(make_pair(min_length, numOps), character_and_amount);
        
        // Check if the key exists in the map
        if (check.find(key) != check.end()) {
            return check[key];
        }

        // Base case
        if (numOps == 0) {
            for (pair<char, int>& tuple : character_and_amount) {
                if (tuple.second > min_length) {
                    return false;
                }
            }
            return true;
        }

        // Recursive case
        for (int index = 0; index < tuple_size; index++) {
            pair<char, int> current_tuple = character_and_amount[index];
            char current_character = current_tuple.first;
            int amount_character = current_tuple.second; 

            if (min_length >= amount_character) {
                continue;
            } else {
                int amountOpsNeed = (amount_character / (min_length + 1));
                remainOps -= amountOpsNeed;
            }
        }

        // If no solution was found, check if we can make enough operations
        check[key] = (remainOps >= 0);
        return check[key];
    }

    int minLength(string s, int numOps) {
        // We will use binary search to find the answer lenK
        // Each lenK, loop through tuple and find how minimum it cost 

        vector<pair<char, int>> character_and_amount = prepare_character_and_amount(s);

        int string_size = s.size();
        int left = 2; 
        int right = string_size;

        int ans = 0;

        if (solve_length_one(s) <= numOps) {
            return 1;
        }

        for (pair<char, int> tuple : character_and_amount) {
            int amount_character = tuple.second;
            ans = max(ans, amount_character);
        }

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (is_ok(mid, character_and_amount, numOps)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};