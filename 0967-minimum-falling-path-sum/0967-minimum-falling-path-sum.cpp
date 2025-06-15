class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        auto check = [&](int r, int c){
            if (r >= 0 && c >= 0 && r < rows && c < cols) return matrix[r][c];
            return INT_MAX;
        };

        for (int row = 1; row < rows; row++){
            for (int col = 0; col < cols; col++){
                matrix[row][col] += min({check(row-1, col-1), check(row-1, col), check(row-1, col+1)});
            }
        }

        return *min_element(matrix[rows-1].begin(), matrix[rows-1].end());
    }
};