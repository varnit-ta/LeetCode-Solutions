class Solution {
public:
    bool check(int x, int y, int row, int col){
        return x >= 0 && y >= 0 && x < row && y < col;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        visited[0][0] = true;

        while (!q.empty()){
            auto [node, dist] = q.front();
            auto [x, y] = node;
            q.pop();

            if (x == rows - 1 && y == cols - 1) return dist + 1;

            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){
                    int newRow = x + i, newCol = y + j;
                    if (check(newRow, newCol, rows, cols) && !visited[newRow][newCol] && grid[newRow][newCol] == 0){
                        q.push({{newRow, newCol}, dist + 1});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }

        return -1;
    }
};