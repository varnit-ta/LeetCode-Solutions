class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int startRow, int startCol) {
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int newRow = row + dx, newCol = col + dy;

                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
                    if (grid[newRow][newCol] == 'O' && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (auto row : {0, rows - 1}) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'O') {
                    bfs(board, visited, row, col);
                }
            }
        }

        for (auto col : {0, cols - 1}) {
            for (int row = 0; row < rows; row++) {
                if (board[row][col] == 'O') {
                    bfs(board, visited, row, col);
                }
            }
        }

        for (int row = 1; row < rows - 1; row++){
            for (int col = 1; col < cols - 1; col++){
                if (!visited[row][col] && board[row][col] == 'O') board[row][col] = 'X';
            }
        }
    }
};