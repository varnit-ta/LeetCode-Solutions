typedef pair<int, pair<int, int>> pii;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto check = [&](int r, int c) -> bool {
            return r >= 0 && c >= 0 && r < n && c < n;
        };

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [time, cell] = pq.top();
            pq.pop();

            int x = cell.first, y = cell.second;

            if (x == n - 1 && y == n - 1) return time;

            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;

                if (check(nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};
