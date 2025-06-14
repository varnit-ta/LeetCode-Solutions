class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<long long>> dp(ROWS, vector<long long>(COLS, 0));

        for (int i = COLS - 1; i >= 0; i--) {
            if (grid[ROWS - 1][i] != 1) dp[ROWS - 1][i] = 1;
            else break;
        }

        for (int i = ROWS - 1; i >= 0; i--) {
            if (grid[i][COLS - 1] != 1) dp[i][COLS - 1] = 1;
            else break;
        }

        for (int i = ROWS - 2; i >= 0; i--) {
            for (int j = COLS - 2; j >= 0; j--) {
                if (grid[i][j] != 1) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
