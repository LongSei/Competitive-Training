class Solution {
public:
    const static int MAX_STRING_LENGTH = 1000 + 5;
    const static int MAX_CHARACTER = 30;
    const static int AMOUNT_STRING = 2;

    string dp[AMOUNT_STRING][MAX_STRING_LENGTH];
    int prev_character[AMOUNT_STRING][MAX_STRING_LENGTH][MAX_CHARACTER];

    void prepare_prev_index_of_character(string& str, int string_index) {
        int string_length = str.size(); 
        for (char alphabet = 'a'; alphabet <= 'z'; alphabet++) {
            prev_character[string_index][0][alphabet - 'a'] = -1;
        }
        for (int index = 0; index < string_length; index++) {
            char character = str[index];

            if (index > 0) {
                for (char alphabet = 'a'; alphabet <= 'z'; alphabet++) {
                    prev_character[string_index][index][alphabet - 'a'] = prev_character[string_index][index - 1][alphabet - 'a'];    
                }
            }
            prev_character[string_index][index][character - 'a'] = index;
        }
    }

    string find_longest_subsequence(string& str1, string& str2) {
        int str1_length = str1.size();
        int str2_length = str2.size(); 

        for (int str1_index = 0; str1_index < str1_length; str1_index++) {
            char str1_character = str1[str1_index];
            for (int str2_index = 0; str2_index < str2_length; str2_index++) {
                char str2_character = str2[str2_index];

                if (dp[(str1_index + 1) % 2][str2_index].size() >= dp[str1_index % 2][str2_index + 1].size()) {
                    dp[(str1_index + 1) % 2][str2_index + 1] = dp[(str1_index + 1) % 2][str2_index];
                } else {
                    dp[(str1_index + 1) % 2][str2_index + 1] = dp[str1_index % 2][str2_index + 1];
                }

                if (str1_character == str2_character && 
                    dp[(str1_index + 1) % 2][str2_index + 1].size() < (dp[str1_index % 2][str2_index] + str1_character).size()) {
                        dp[(str1_index + 1) % 2][str2_index + 1] = dp[str1_index % 2][str2_index] + str1_character;
                }
            }
        }

        return dp[str1_length % 2][str2_length];
    }

    string construct_answer(string& str1, string& str2, string& subsequence) {
        string answer = "";

        int str1_index = str1.size() - 1;
        int str2_index = str2.size() - 1;
        int subsequence_index = subsequence.size() - 1;

        while (subsequence_index >= 0 && (str1_index >= 0 || str2_index >= 0)) {
            char character = subsequence[subsequence_index];

            int next_str1_index = str1_index >= 0 ? prev_character[0][str1_index][character - 'a'] : -1;
            int next_str2_index = str2_index >= 0 ? prev_character[1][str2_index][character - 'a'] : -1;

            while (next_str1_index >= 0 && str1_index > next_str1_index) {
                answer = str1[str1_index] + answer;
                str1_index -= 1;
            }
            str1_index -= 1;
            while (next_str2_index >= 0 && str2_index > next_str2_index) {
                answer = str2[str2_index] + answer;
                str2_index -= 1;
            }
            str2_index -= 1;

            answer = character + answer;
            subsequence_index -= 1;
        }

        while (str1_index >= 0) {
            answer = str1[str1_index] + answer;
            str1_index -= 1;
        }
        while (str2_index >= 0) {
            answer = str2[str2_index] + answer;
            str2_index -= 1;
        }
        return answer;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        prepare_prev_index_of_character(str1, 0);
        prepare_prev_index_of_character(str2, 1);
        string longest_subsequence = find_longest_subsequence(str1, str2);

        string answer = construct_answer(str1, str2, longest_subsequence);

        return answer;
    }
};
