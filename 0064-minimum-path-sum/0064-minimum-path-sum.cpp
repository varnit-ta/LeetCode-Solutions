class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 1; i < cols; i++)grid[0][i] = grid[0][i] + grid[0][i-1];
        for (int i = 1; i < rows; i++)grid[i][0] = grid[i][0] + grid[i-1][0];

        for (int row = 1; row < rows; row++){
            for (int col = 1; col < cols; col++){
               grid[row][col] = grid[row][col] + min(grid[row - 1][col],grid[row][col - 1]);
            }
        }

        return grid[rows - 1][cols - 1];
    }
};