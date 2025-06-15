class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        function<int(int, int, int)> dfs = [&](int r, int c1, int c2) -> int {
            if (c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols)
                return INT_MIN;

            if (dp[r][c1][c2] != -1)
                return dp[r][c1][c2];

            int result = 0;
            result += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];

            if (r != rows - 1) {
                int max_candy = INT_MIN;
                for (int d1 = -1; d1 <= 1; ++d1) {
                    for (int d2 = -1; d2 <= 1; ++d2) {
                        max_candy = max(max_candy, dfs(r + 1, c1 + d1, c2 + d2));
                    }
                }
                result += max_candy;
            }

            return dp[r][c1][c2] = result;
        };

        return dfs(0, 0, cols - 1);
    }
};
