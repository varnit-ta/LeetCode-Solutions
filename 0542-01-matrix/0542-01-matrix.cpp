class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> res(rows, vector<int>(cols, INT_MAX));
        queue<pair<pair<int, int>, int>> q;

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (mat[row][col] == 0){
                    res[row][col] = 0;
                    q.push({{row, col}, 0});
                    visited[row][col] = true;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int newRow, newCol;

        auto check = [&](int row, int col) -> bool{
            return row >= 0 && row < rows && col >= 0 && col < cols;
        };

        while (!q.empty()){
            auto [cord, step] = q.front();
            auto [row, col] = cord;
            q.pop();

            for (auto [dx, dy]: dir){
                newRow = row + dx;
                newCol = col + dy;

                if (check(newRow, newCol) && !visited[newRow][newCol] && mat[newRow][newCol] == 1){
                    res[newRow][newCol] = min(res[newRow][newCol], step + 1);
                    q.push({{newRow, newCol}, step + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return res;
    }
};