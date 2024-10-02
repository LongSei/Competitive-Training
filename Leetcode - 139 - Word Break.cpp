
class TrieNode {
public:
    std::map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) const {
        TrieNode* node = findNode(word);
        return (node != nullptr && node->isEndOfWord);
    }

    bool startsWith(const std::string& prefix) const {
        return (findNode(prefix) != nullptr);
    }

private:
    TrieNode* findNode(const std::string& str) const {
        TrieNode* current = root;
        for (char c : str) {
            if (current->children.find(c) == current->children.end()) {
                return nullptr;
            }
            current = current->children[c];
        }
        return current;
    }
};

class Solution {
private: 
    Trie trie; 
    map<string, bool> check;
    map<string, bool> dp;
public:
    bool dfs(string& remainString) {

        if (remainString == "") {
            return true;
        }

        if (check[remainString]) {
            return dp[remainString];
        }
        
        string currentString = "";
        check[remainString] = true;
        for (int i = 0; i < remainString.size(); i++) {
            currentString += remainString[i];  
            if (currentString.size() > 20) {
                return dp[remainString] = false;
            }
            if (trie.search(currentString) == true) {
                string remainingPart = remainString.substr(i + 1);  
                if (dfs(remainingPart)) {
                    return dp[remainString] = true;
                }
            }
        }   
        return dp[remainString] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            trie.insert(word);
        }
        return dfs(s);
    }
};