class TrieNode {
public:
    unordered_map<char, TrieNode*> list_child; 
    int longest_common_suffix_index;

    TrieNode() : longest_common_suffix_index(-1) {}
};


class Solution {
public:
    void add_word_from_end_to_begin(TrieNode* root, int& string_index, vector<string>& wordsContainer, int& limit_add) {
        int siz = wordsContainer[string_index].size() - 1;
        string str = wordsContainer[string_index];
        char current_character = ' ';
        int current_string_index = 0;
        int current_size = 0;
        int check_size = wordsContainer[string_index].size();

        for (int current_index = siz; current_index >= max(0, siz - limit_add + 1); current_index -= 1) {
            current_character = str[current_index];
            TrieNode* current_node = nullptr; 

            if ((*root).list_child[current_character] == nullptr) {
                current_node = new TrieNode();
                (*root).list_child[current_character] = current_node;
            } else {
                current_node = (*root).list_child[current_character];
            }

            if ((*current_node).longest_common_suffix_index == -1) {
                (*current_node).longest_common_suffix_index = string_index;
            } else {
                current_string_index = (*current_node).longest_common_suffix_index;
                current_size = wordsContainer[current_string_index].size();
                if ((current_size > check_size) ||
                    (current_size == check_size && string_index < current_string_index)) {
                    (*current_node).longest_common_suffix_index = string_index;
                }
            }

            root = current_node;
        }
    }

    int query(TrieNode* root, string& query, int current_index) {
        TrieNode* current_node = root;
        int result = -1;
        int char_index = 0;
        char current_character = 'a';

        for (int i = current_index; i >= 0; --i) {
            current_character = query[i];

            if (!current_node->list_child[current_character]) {
                break;
            }

            current_node = current_node->list_child[current_character];
            result = current_node->longest_common_suffix_index;
        }

        return result;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        int n = wordsContainer.size();
        int default_answer = 0;

        for (int idx = 0; idx < n; idx++) {
            int current_size = wordsContainer[idx].size(); 
            int answer_size = wordsContainer[default_answer].size();

            if (answer_size > current_size) {
                default_answer = idx;
            }
        }

        int limit_add = 0;
        int m = wordsQuery.size();
        for (int idx = 0; idx < m; idx++) {
            int siz = wordsQuery[idx].size();
            limit_add = max(limit_add, siz);
        }

        for (int idx = 0; idx < n; idx++) {
            add_word_from_end_to_begin(root, idx, wordsContainer, limit_add);
        }

        vector<int> result;
        for (string& str : wordsQuery) {
            int ans = query(root, str, str.size() - 1);
            ans = ans != -1 ? ans : default_answer;
            result.push_back(ans);
        }
        
        return result;
    }
};