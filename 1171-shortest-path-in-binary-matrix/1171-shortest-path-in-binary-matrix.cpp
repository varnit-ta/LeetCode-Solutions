class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 1});
        visited[0][0] = true;

        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1},  {1, 0}, {1, 1}
        };

        while (!q.empty()) {
            auto [node, dist] = q.front(); q.pop();
            auto [x, y] = node;

            if (x == rows - 1 && y == cols - 1) return dist;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                    !visited[nx][ny] && grid[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return -1;
    }
};
