class Solution {
public:
    map<string, vector<string>> adj;
    map<string, int> dp;
    map<string, vector<string>> parent;
    bool check(string a, string b) {
        bool checkDiff = false;
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (checkDiff == true) {
                    return false;
                }
                checkDiff = true;
            }
        }
        return true;
    }
    set<vector<string>> result;
    void createResult(string currentString, string beginWord, stack<string> currentResult) {
        if (currentString == beginWord) {
            vector<string> ans; 
            ans.push_back(beginWord);
            while (currentResult.empty() == false) {
                ans.push_back(currentResult.top());
                currentResult.pop();
            }
            result.insert(ans);
            return;
        }
        for (string parent : parent[currentString]) {
            stack<string> st = currentResult;
            st.push(currentString);
            createResult(parent, beginWord, st);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            if (check(beginWord, wordList[i])) {
                adj[beginWord].push_back(wordList[i]);
            }
            for (int j = i + 1; j < wordList.size(); j++) {
                if (check(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        dp[beginWord] = 1000000;
        for (auto v : wordList) {
            dp[v] = 1000000;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push(pair<int, string>(1, beginWord));
        parent[beginWord].push_back("");
        while (pq.empty() == false) {
            pair<int, string> top = pq.top();
            pq.pop();
            int dist = top.first;
            string node = top.second;
            for (auto v : adj[node]) {
                int newDist = dist + 1;
                if (dp[v] > newDist) {
                    dp[v] = newDist;
                    pq.push(pair<int, string>(newDist, v));
                    parent[v].clear();
                    parent[v].push_back(node);
                }
                else if (dp[v] == newDist) {
                    parent[v].push_back(node);
                }
            }
        }
        stack<string> st;
        createResult(endWord, beginWord, st);
        vector<vector<string>> newResult;
        for (auto v : result) {
            newResult.push_back(v);
        }
        return newResult;
    }
};