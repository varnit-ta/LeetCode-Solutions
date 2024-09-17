class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        stack<pair<int, int>> stk;

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (matrix[i][j] == 0){
                    stk.push({i, j});
                }
            }
        }

        while (!stk.empty()) {
            pair<int, int> cord = stk.top();
            stk.pop();

            int row = cord.first;
            int col = cord.second;

            for(int i = 0; i < cols; i++) {
                matrix[row][i] = 0;
            }

            for(int i = 0; i < rows; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};