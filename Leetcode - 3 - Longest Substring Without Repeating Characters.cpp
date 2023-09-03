class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[5 * 10000 + 5];
        for (int i = 0; i <= s.size() + 1; i++) {
            arr[i] = 0;
        }
        map<char, int> check;
        int ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (check[s[i - 1]] == 0) {
                arr[i] = arr[i - 1] + 1;
                check[s[i - 1]] = i;
            }
            else {
                arr[i] = min(arr[i - 1] + 1, i - check[s[i - 1]]);
                check[s[i - 1]] = i;
            }
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};