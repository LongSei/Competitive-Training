
class TrieNode {
public: 
    char character; 
    long long val = 0;
    vector<TrieNode*> child_node;

    TrieNode() : character('!'), val(0) {}

    TrieNode(char character) : character(character), val(0) {}
};

class Solution {
public:
    long long dp[500005];

    bool check_suffix(string& str, long long prefix_index) {
        long long string_size = str.size();
        long long len_check = prefix_index + 1;
        for (long long idx = 0; idx <= prefix_index; idx++) {
            long long prefix = idx;
            long long suffix = (string_size - len_check) + idx;

            if (str[prefix] != str[suffix]) {
                return false;
            }
        }
        return true;
    }

    void add_node(TrieNode& parent_node, string& str, long long current_insert_index, long long string_index) {
        TrieNode* next_node = nullptr;
        char current_character_insert = str[current_insert_index];

        for (TrieNode* child : parent_node.child_node) {
            if (child->character == current_character_insert) {
                next_node = child;
                break;
            }
        }

        if (!next_node) {
            next_node = new TrieNode(current_character_insert);
            parent_node.child_node.push_back(next_node);
        }
         
        // Check any end string at node 
        if (next_node->val != 0) {
            if (check_suffix(str, current_insert_index)) {
                dp[string_index] += next_node->val;
            }
        }
        
        // Check end string to stop adding 
        if (current_insert_index == str.size() - 1) {
            next_node->val += 1;
        } else {
            add_node(*next_node, str, current_insert_index + 1, string_index);
        }
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        long long amount_word = words.size();
        TrieNode root = TrieNode('$');
        for (long long idx = 0; idx < amount_word; idx++) {
            add_node(root, words[idx], 0, idx);
        }

        long long ans = 0;
        for (long long idx = 0; idx < amount_word; idx++) {
            ans += dp[idx];
        }
        return ans;
    }
};