class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRow(n, 0), maxCol(n, 0);

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < n; j++) {
                maxCol[j] = max(maxCol[j], grid[i][j]);
                mx = max(mx, grid[i][j]);
            }
            maxRow[i] = mx;
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idealCase = min(maxRow[i], maxCol[j]);
                total += max(0, idealCase - grid[i][j]);
            }
        }

        return total;
    }
};