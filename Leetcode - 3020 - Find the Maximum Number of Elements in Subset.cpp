class Solution {
public:
    const static int MAX = 100000 + 1;
    map<int, int> cnt; 
    map<int, int> full_set; 

    int maximumLength(vector<int>& nums) {
        for (int v : nums) {
            cnt[v] += 1; 
        }
        sort(nums.begin(), nums.end());
        int answer = cnt[1] - (cnt[1] % 2 == 0 ? 1 : 0); 
        for (int v : nums) {
            full_set[v] = 1; 
            answer = max(answer, full_set[v]);
            if (sqrt(v) * sqrt(v) == v && cnt[sqrt(v)] >= 2 && sqrt(v) != v) {
                full_set[v] = full_set[sqrt(v)] + 2; 
                answer = max(answer, full_set[v]);
            }
        }
        return answer;
    }
};
