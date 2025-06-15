class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, 0)));

        for (int r = rows - 1; r >= 0; --r) {
            for (int c1 = 0; c1 < cols; ++c1) {
                for (int c2 = 0; c2 < cols; ++c2) {
                    int max_candy = 0;
                    for (int d1 = -1; d1 <= 1; ++d1) {
                        for (int d2 = -1; d2 <= 1; ++d2) {
                            int nc1 = c1 + d1, nc2 = c2 + d2;
                            if (nc1 >= 0 && nc1 < cols && nc2 >= 0 && nc2 < cols && r + 1 < rows) {
                                max_candy = max(max_candy, dp[r + 1][nc1][nc2]);
                            }
                        }
                    }
                    int cherries = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
                    dp[r][c1][c2] = cherries + max_candy;
                }
            }
        }
        return dp[0][0][cols - 1];
    }
};
