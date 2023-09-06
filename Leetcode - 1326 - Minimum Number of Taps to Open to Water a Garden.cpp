class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> segment;
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            segment.push(pair<int, int>(left, right));
        }
        int ans = 0;
        int index = 0;
        int indexCheck = 0;
        while (indexCheck <= n) {
            int maxRight = 0;
            while (segment.empty() == false && segment.top().first <= indexCheck) {
                maxRight = max(maxRight, segment.top().second);
                segment.pop();
            }
            if (maxRight == 0 || maxRight <= indexCheck) {
                return -1;
            }
            indexCheck = max(indexCheck, maxRight);
            ans += 1;
            if (maxRight == n) {
                return ans;
            }
        }
        return ans;
    }
};