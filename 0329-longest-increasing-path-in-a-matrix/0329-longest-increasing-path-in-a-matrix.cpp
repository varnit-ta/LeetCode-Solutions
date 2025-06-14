class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int row, int col) {
        visited[row][col] = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto check = [&](int r, int c) {
            return r >= 0 && c >= 0 && r < matrix.size() && c < matrix[0].size();
        };

        for (auto& [dx, dy] : dir) {
            int nrow = row + dx;
            int ncol = col + dy;

            if (check(nrow, ncol) && matrix[row][col] < matrix[nrow][ncol]) {
                if (visited[nrow][ncol] == -1)
                    dfs(matrix, visited, nrow, ncol);
                visited[row][col] = max(visited[row][col], visited[nrow][ncol] + 1);
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, -1));


        int maxLen = INT_MIN;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (visited[row][col] == -1)
                    dfs(matrix, visited, row, col);
                maxLen = max(maxLen, visited[row][col] + 1);
            }
        }

        return maxLen;
    }
};