class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int leftRow = 0, rightRow = n - 1;
        int row = 0;
        while (leftRow <= rightRow) {
            int mid = (leftRow + rightRow) >> 1;
            if (matrix[mid][0] <= target) {
                row = mid;
                leftRow = mid + 1;
            }
            else {
                rightRow = mid - 1;
            }
        }
        int leftCol = 0, rightCol = m - 1;
        while (leftCol <= rightCol) {
            int mid = (leftCol + rightCol) >> 1;
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                leftCol = mid + 1;
            }
            else {
                rightCol = mid - 1;
            }
        }
        return false;
    }
};