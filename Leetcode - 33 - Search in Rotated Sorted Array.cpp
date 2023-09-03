class Solution {
public:
    int search(vector<int>& nums, int target) {
        int siz = nums.size() - 1;
        int left = 0, right = siz;
        int ans = -1;
        bool isRotated = false;
        if (target > nums[siz]) {
            isRotated = true;
        }   
        int lastRotated = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[siz]) {
                lastRotated = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (isRotated == false) {
            left = lastRotated + 1;
            right = siz;
        }
        else {
            left = 0;
            right = lastRotated;
        }

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};