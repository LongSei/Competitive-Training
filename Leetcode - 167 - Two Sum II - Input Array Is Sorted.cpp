class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numbers_size = numbers.size(); 
        for (int index = 0; index < numbers_size - 1; index++) {
            int next_index = -1;
            int left = index + 1;
            int right = numbers_size - 1; 
            while (left <= right) {
                int mid = (left + right) / 2; 
                if (numbers[index] + numbers[mid] == target) {
                    next_index = mid;
                    break;
                } else if (numbers[index] + numbers[mid] < target) {
                    left = mid + 1; 
                } else {
                    right = mid - 1;
                }
            }
            if (next_index != -1) {
                vector<int> answer; 
                answer.push_back(index + 1);
                answer.push_back(next_index + 1);
                return answer;
            } 
        }
        return vector<int>();
    }
};
