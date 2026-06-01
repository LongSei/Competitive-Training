class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0; 
        int height_size = height.size(); 
        int left_pointer = 0; 
        int right_pointer = height_size - 1; 
        while (left_pointer < height_size && height[left_pointer] == 0) {
            left_pointer += 1;
        }
        while (right_pointer >= 0 && height[right_pointer] == 0) {
            right_pointer -= 1;
        }

        while (left_pointer < right_pointer) {
            if (height[left_pointer] < height[right_pointer]) {
                answer += max(0, height[left_pointer] - height[left_pointer + 1]);
                height[left_pointer + 1] = max(height[left_pointer], height[left_pointer + 1]); 
                left_pointer += 1;
            } else {
                answer += max(0, height[right_pointer] - height[right_pointer - 1]);
                height[right_pointer - 1] = max(height[right_pointer - 1], height[right_pointer]);
                right_pointer -= 1;
            }
        }

        return answer; 
    }
};
