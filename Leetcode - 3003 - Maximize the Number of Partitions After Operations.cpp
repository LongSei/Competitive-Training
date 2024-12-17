class Solution {
public:
    int nearest_partial[27];
    int find_amount_partial(string& s, int k) {
        int ans = 0;
        int string_size = s.size();

        for (int character = 0; character < 27; character++) {
            nearest_partial[character] = -1;
        }

        int cumulative_element = 0;
        for (int idx = 0; idx < string_size; idx++) {
            int character_numerical = s[idx] - 'a';

            bool is_partial_does_not_have_character = nearest_partial[character_numerical] != ans;
            if (is_partial_does_not_have_character) {
                bool is_partial_enough_element = cumulative_element == k;
                if (is_partial_enough_element) {
                    cumulative_element = 0;
                    ans += 1;
                }
                cumulative_element += 1;
                nearest_partial[character_numerical] = ans;
            } else {
                continue;
            }
        }
        return ans + 1;
    }

    vector<int> find_could_modify(string& s, int k) {
        int string_size = s.size();
        vector<int> result;

        for (int character = 0; character < 27; character++) {
            nearest_partial[character] = -1;
        }
        int ans = 0;
        int cumulative_element = 0;
        for (int idx = 0; idx < string_size; idx++) {
            int character_numerical = s[idx] - 'a';

            bool is_partial_does_not_have_character = nearest_partial[character_numerical] != ans;
            if (is_partial_does_not_have_character) {
                bool is_partial_enough_element = cumulative_element == k;
                if (is_partial_enough_element) {
                    cumulative_element = 0;
                    ans += 1;
                }
                cumulative_element += 1;
                nearest_partial[character_numerical] = ans;
            } else {
                result.push_back(idx);
            }
        }
        return result;
    }

    int solve_k_equal_max(string& s, int k) {
        int ans = 1;
        return 1;
    }

    int check[27];
    int solve_k_equal_min(string& s, int k) {
        int string_size = s.size();
        int ans = 0;
        bool is_change = false;
        for (int idx = 0; idx < string_size; idx++) {
            int character_numerical = s[idx] - 'a';
            if (check[character_numerical] != -1 && is_change == false) {
                s[idx] = '{';
                ans = max(ans, find_amount_partial(s, k));
                s[idx] = character_numerical + 'a';
            }
            check[character_numerical] = 0;
        }

        return ans;
    }

    int solve_k_general(string& s, int k) {
        vector<int> change_idx = find_could_modify(s, k);
        int ans = find_amount_partial(s, k);
        for (int idx : change_idx) {
            char temp = s[idx];
            if (k >= 13 && k < 25) {
                for (char modify_char = 'a'; modify_char <= 'z'; modify_char++) {
                    s[idx] = modify_char;
                    ans = max(ans, find_amount_partial(s, k));
                    s[idx] = temp;
                }
            } else {
                s[idx] = '{';
                ans = max(ans, find_amount_partial(s, k));
                s[idx] = temp;
            }
        }
        return ans;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        int tot = 0;
        for (char c : s) {
            int num = c - 'a';
            if (nearest_partial[num] == 0) {
                nearest_partial[num] = 1;
                tot += 1;
            }
        }
        k = min(26, min(k, tot + 1));
        if (k == 1) {
            return solve_k_equal_min(s, k);
        }
        if (k == 26) {
            return solve_k_equal_max(s, k);
        }
        return solve_k_general(s, k);
    }
};