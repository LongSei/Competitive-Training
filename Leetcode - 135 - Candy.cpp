class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr;
        
        arr.push_back(1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                arr.push_back(arr[arr.size() - 1] + 1);
            }
            else {            
                int index = i;
                arr.push_back(1);
                while (index >= 1 && ratings[index - 1] > ratings[index]) {
                    arr[index - 1] = max(arr[index - 1], arr[index] + 1);    
                    index -= 1;
                }
            }
        }

        int ans = 0;
        for (int v : arr) {
            ans += v;
        }
        return ans;
    }
};