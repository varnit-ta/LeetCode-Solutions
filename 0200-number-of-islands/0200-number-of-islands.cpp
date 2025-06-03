class Solution {
public:
    bool check(vector<vector<char>>& grid, int newRow, int newCol){
        return newCol >= 0 && newCol < grid[0].size() && newRow >= 0 && newRow < grid.size();
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int startRow, int startCol){
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int newRow, newCol;

        while (!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for (auto [dx, dy]: dir){
                newRow = row + dx;
                newCol = col + dy;

                if (check(grid, newRow, newCol) && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int cnt = 0;

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == '1' && !visited[row][col]){
                    bfs(grid, visited, row, col);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};