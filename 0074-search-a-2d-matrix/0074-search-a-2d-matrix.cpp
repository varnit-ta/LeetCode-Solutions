class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int y = mid / cols, x = mid % cols;

            if (matrix[y][x] == target) return true;

            if (matrix[y][x] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};
