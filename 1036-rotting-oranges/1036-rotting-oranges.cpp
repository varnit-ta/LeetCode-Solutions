class Solution {
public:
    queue<pair<int, int>> q;
    int freshOrange = 0;
    int minTime = 0;

    void bfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int rows, int cols) {
        while (!q.empty()) {
            int size = q.size();
            minTime++;

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (row > 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == false) {
                    visited[row - 1][col] = true;
                    q.push({row - 1, col});
                    freshOrange--;
                }
                if (row < rows - 1 && grid[row + 1][col] == 1 && visited[row + 1][col] == false) {
                    visited[row + 1][col] = true;
                    q.push({row + 1, col});
                    freshOrange--;
                }
                if (col > 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == false) {
                    visited[row][col - 1] = true;
                    q.push({row, col - 1});
                    freshOrange--;
                }
                if (col < cols - 1 && grid[row][col + 1] == 1 && visited[row][col + 1] == false) {
                    visited[row][col + 1] = true;
                    q.push({row, col + 1});
                    freshOrange--;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }

        if (freshOrange == 0)
            return 0;

        bfs(visited, grid, rows, cols);

        return freshOrange == 0 ? minTime - 1: -1;
    }
};