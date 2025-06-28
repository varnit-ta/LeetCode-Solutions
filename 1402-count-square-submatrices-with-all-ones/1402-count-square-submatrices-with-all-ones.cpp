class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> mat(rows + 1, vector<int>(cols + 1, 0));

        int total = 0;

        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= cols; j++){
                if (matrix[i - 1][j - 1] == 1){
                    mat[i][j] = 1 + min({mat[i-1][j-1], mat[i-1][j], mat[i][j-1]});
                    total += mat[i][j];
                }
            }
        }

        return total;
    }
};