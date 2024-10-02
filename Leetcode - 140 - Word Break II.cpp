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
public:
    vector<string> dfs(string remainString) {
        if (remainString == "") {
            return {""}; 
        }
        
        string currentString = "";
        vector<string> result;
        
        for (int i = 0; i < remainString.size(); i++) {
            currentString += remainString[i];  
            
            if (trie.search(currentString) == true) {
                string remainingPart = remainString.substr(i + 1);  
                vector<string> newStrings = dfs(remainingPart);  
                
                for (auto& str : newStrings) {
                    if (str == "") {
                        result.push_back(currentString);
                    } else {
                        result.push_back(currentString + " " + str);
                    }
                }
            }
        }
        
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict) {
            trie.insert(word);
        }
        return dfs(s);
    }
};