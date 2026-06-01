class Solution {
public:
    static bool intervals_comparator(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervals_comparator); 
        vector<vector<int>> answer;
        for (int index = 0; index < intervals.size(); index++) {
            if (answer.empty() || (intervals[index][0] > answer[answer.size() - 1][1])) {
                answer.push_back(intervals[index]);
            } else {
                answer[answer.size() - 1][1] = max(answer[answer.size() - 1][1], intervals[index][1]);
            } 
        }
        return answer; 
    }
};
