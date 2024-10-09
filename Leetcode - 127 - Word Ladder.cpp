class Solution {
public:
    map<string, vector<string>> adj;
    map<string, int> dp;
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
        while (pq.empty() == false) {
            pair<int, string> top = pq.top();
            pq.pop();
            int dist = top.first;
            string node = top.second;
            if (dp[node] <= dist) {
                continue;
            }
            dp[node] = dist;
            for (auto v : adj[node]) {
                int newDist = dist + 1;
                pq.push(pair<int, string>(newDist, v));
            }
        }
        return (dp[endWord] != 1000000 ? dp[endWord] : 0);
    }
};