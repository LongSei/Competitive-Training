class Solution {
public:
    queue<int> char_position[27];
    bool check[100005];
    stack<int> acc_index[2]; 

    char rev(char x) {
        int numerical_x = x - 'a';
        int reverse_numerical_x = 'z' - numerical_x;
        
        return char(reverse_numerical_x);
    }

    long long calculateScore(string s) {
        int string_size = s.size();
        for (int index = 0; index < string_size; index++) {
            char character = s[index]; 
            int numerical_character = character - 'a';
            
            char_position[numerical_character].push(index);
            check[index] = false;
        }
        
        long long ans = 0;
        for (char character = 'a'; character <= 'z'; character++) {
            acc_index[0] = stack<int>();
            acc_index[1] = stack<int>();
            int numerical_character = character - 'a';
            int reverse_character = rev(character);
            int numerical_reverse_character = reverse_character - 'a';

            while (
                numerical_character <= numerical_reverse_character && 
                char_position[numerical_character].empty() == false && 
                char_position[numerical_reverse_character].empty() == false
            ) {

                if (char_position[numerical_character].front() <= char_position[numerical_reverse_character].front()) {
                    while 
                    (
                        char_position[numerical_character].empty() == false && 
                        char_position[numerical_character].front() <= char_position[numerical_reverse_character].front()
                    ) {
                        acc_index[0].push(char_position[numerical_character].front());
                        char_position[numerical_character].pop();
                        // cout << "T1" << endl;
                    }
                    
                    while (
                        acc_index[0].empty() == false && 
                        (
                            (
                                char_position[numerical_character].empty() == true &&
                                char_position[numerical_reverse_character].empty() == false
                            ) ||
                            (
                                char_position[numerical_reverse_character].empty() == false && 
                                char_position[numerical_character].empty() == false && 
                                char_position[numerical_reverse_character].front() <= char_position[numerical_character].front()
                            )
                        )
                    ) {
                        int index = acc_index[0].top(); acc_index[0].pop();
                        int reverse_index = char_position[numerical_reverse_character].front(); char_position[numerical_reverse_character].pop();

                        ans += abs(index - reverse_index);
                    }
                } else {
                    while 
                    (
                        char_position[numerical_reverse_character].empty() == false && 
                        char_position[numerical_reverse_character].front() <= char_position[numerical_character].front()
                    ) {
                        acc_index[1].push(char_position[numerical_reverse_character].front());
                        char_position[numerical_reverse_character].pop();
                        // cout << "T2" << endl;
                    }

                    while (
                        acc_index[1].empty() == false && 
                        (   (
                                char_position[numerical_reverse_character].empty() == true &&
                                char_position[numerical_character].empty() == false
                            )  ||
                            (
                                char_position[numerical_reverse_character].empty() == false && 
                                char_position[numerical_character].empty() == false && 
                                char_position[numerical_character].front() <= char_position[numerical_reverse_character].front()
                            )
                        )
                    ) {
                        int index = acc_index[1].top(); acc_index[1].pop();
                        int reverse_index = char_position[numerical_character].front(); char_position[numerical_character].pop();

                        ans += abs(index - reverse_index);
                    }
                }
                
            }
        }
        
        return ans;
    }
};