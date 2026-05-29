class Solution {
public:
    string compressedString(string word) {
        string answer = ""; 
        int amount = 1;
        char cur = word[0]; 
        
        int word_size = word.size(); 
        for (int index = 1; index < word_size; index++) {
            if (word[index] == cur) {
                amount += 1;
                if (amount > 9) {
                    answer.push_back((amount - 1) + '0');
                    answer.push_back(cur); 
                    amount = 1;
                }
            } else {
                answer.push_back((amount) + '0');
                answer.push_back(cur); 
                amount = 1;
                cur = word[index];
            }
        }
        answer.push_back((amount) + '0');
        answer.push_back(cur); 
        return answer;
    }
};
