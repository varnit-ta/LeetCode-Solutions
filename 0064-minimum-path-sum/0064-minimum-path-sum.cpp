class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        dp[0][0] = grid[0][0];
        for (int i = 1; i < cols; i++) dp[0][i] = grid[0][i] + dp[0][i-1];
        for (int i = 1; i < rows; i++) dp[i][0] = grid[i][0] + dp[i-1][0];

        for (int row = 1; row < rows; row++){
            for (int col = 1; col < cols; col++){
                dp[row][col] = grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};